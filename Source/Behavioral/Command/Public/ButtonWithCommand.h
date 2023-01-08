#pragma once

#include <iostream>
#include <vector>
#include "Command.h"

class ButtonWithCommand
{
public:
	ButtonWithCommand() = default;
	virtual ~ButtonWithCommand() = default;

	virtual void Click() = 0;
	virtual void Drag() = 0; 
};

class ButtonWithSimpleCommand : public ButtonWithCommand
{
public:
	ButtonWithSimpleCommand() = default;
	~ButtonWithSimpleCommand() = default;

	virtual void Click() override
	{
		std::cout << "Button clicked\n";
		if (CommandToClick.IsBinded())
		{
			CommandToClick.Excecute();
		}
	}
	virtual void Drag() override {}
	Command<void()>& BindOnClick() { return CommandToClick; }

private:
	Command<void()> CommandToClick;
};

class ButtonWithArgumentsCommand : public ButtonWithCommand
{
public:
	ButtonWithArgumentsCommand() = default;
	~ButtonWithArgumentsCommand() = default;

	virtual void Click() override
	{
		std::cout << "Button clicked\n";
		if (CommandToClick.IsBinded())
		{
			CommandToClick.Excecute("String from button");
		}
	}

	virtual void Drag() override
	{
		std::cout << "Button dragged\n";
		if (CommandToDrag.IsBinded())
		{
			CommandToDrag.Excecute({1, 2, 3, 4, 5});
		}
	}

	auto& BindOnClick() { return CommandToClick; }
	auto& BindOnDrag() { return CommandToDrag; }

private:
	Command<void(const std::string&)> CommandToClick;
	Command<void(const std::vector<int>&)> CommandToDrag;
};