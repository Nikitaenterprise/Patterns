#pragma once

#include <string>
#include <iostream>
#include <memory>

enum class EHandleType
{
	Handled,
	Unhandled
};

class Handle
{
public:
	Handle() = delete;
	Handle(std::string&& InString, EHandleType InHandleType) : Message(std::move(InString)), HandleType(InHandleType) {}
	const std::string& GetMessage() const { return Message; }
	
	EHandleType HandleType;

protected:
	std::string Message;
};

std::ostream& operator<<(std::ostream& os, Handle InHandle)
{
	std::string out = "Click was ";
	out += InHandle.HandleType == EHandleType::Handled ? "handled " : "unhandled ";
	out += "with messsage: '";
	out += InHandle.GetMessage();
	out += "'";
	return os << out;
}

class IWidget
{
public:
	IWidget() = delete;
	IWidget(std::shared_ptr<IWidget> InSuccessor) : Successor(InSuccessor) {}
	virtual ~IWidget() = default;
	
	virtual Handle Click() = 0;

protected:
	std::shared_ptr<IWidget> Successor;
};

class Button : public IWidget
{
public:
	Button() = delete;
	Button(std::shared_ptr<IWidget> InSuccessor) : IWidget(InSuccessor) {}
	virtual ~Button() override = default;

	virtual Handle Click() override
	{
		if (Successor)
		{
			return Successor->Click();
		}
		return Handle("Clicked on a button", EHandleType::Handled);
	}
};

class InfoButton : public IWidget
{
public:
	InfoButton() = delete;
	InfoButton(std::shared_ptr<IWidget> InSuccessor) : IWidget(InSuccessor) {}
	virtual ~InfoButton() override = default;

	virtual Handle Click() override
	{
		DoWork();
		if (Successor)
		{
			return Successor->Click();
		}
		return Handle("Clicked on an info button", EHandleType::Handled);
	}

protected:
	void DoWork() { std::cout << "Info button doing work\n"; }
};


class Overlay : public IWidget
{
public:
	Overlay() = delete;
	Overlay(std::shared_ptr<IWidget> InSuccessor) : IWidget(InSuccessor) {}
	virtual ~Overlay() override = default;

	virtual Handle Click() override
	{
		if (Successor)
		{
			return Successor->Click();
		}
		return Handle("Can't click on overlay", EHandleType::Unhandled);
	}
};