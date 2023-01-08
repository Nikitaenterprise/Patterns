#pragma once

#include <iostream>

namespace AbstractFactory
{
class IWidget
{
public:
	IWidget() = default;
	virtual ~IWidget() = default;

	virtual void WhoAmI() = 0;
};

class UMacWidget : public IWidget
{
public:
	UMacWidget() = default;
	virtual ~UMacWidget() override = default;

	void WhoAmI() override
	{
		std::cout << "I'm mac widget\n";
	}
};

class UWindowsWidget : public IWidget
{
public:
	UWindowsWidget() = default;
	virtual ~UWindowsWidget() override = default;

	void WhoAmI() override
	{
		std::cout << "I'm windows widget\n";
	}
};

class IAbstractWidgetFactory
{
public:
	IAbstractWidgetFactory() = default;
	virtual ~IAbstractWidgetFactory() = default;

	virtual void CreateWidget() = 0;
};

class UMacWidgetFactory : public IAbstractWidgetFactory
{
public:
	UMacWidgetFactory() = default;
	virtual ~UMacWidgetFactory() override = default;

	void CreateWidget() override
	{
		std::cout << "Mac widget created\n";
		UMacWidget Widget;
		Widget.WhoAmI();
	}
};

class UWindowsWidgetFactory : public IAbstractWidgetFactory
{
public:
	UWindowsWidgetFactory() = default;
	virtual ~UWindowsWidgetFactory() override = default;
	void CreateWidget() override
	{
		std::cout << "Windows widget created\n";
		UWindowsWidget Widget;
		Widget.WhoAmI();
	}
};
}