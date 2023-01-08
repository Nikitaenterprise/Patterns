#pragma once

#include <iostream>
#include <string>

class IWearable
{
public:
	IWearable() = default;
	virtual ~IWearable() = default;
	virtual void Wear() = 0;

protected:
	std::string Name = "None";
};

class BaseWear : public IWearable
{
public:
	BaseWear() = delete;
	virtual ~BaseWear() override = default;

	BaseWear(std::string&& InName)
	{
		Name = std::move(InName);
	}
	void Wear() override
	{
		std::cout << "\nWearing " << Name << " ";
	}
};

class TopWear : public BaseWear
{
public:
	TopWear() = delete;
	virtual ~TopWear() override = default;

	TopWear(std::string&& InName) : BaseWear(std::move(InName)) {}
	void Wear() override
	{
		BaseWear::Wear();
		std::cout << "and it's on top";
	}
};

class ColoredWear : public BaseWear
{
public:
	ColoredWear() = delete;
	virtual ~ColoredWear() override = default;

	ColoredWear(std::string&& InName, std::string&& InColor, std::shared_ptr<BaseWear> InWear) : BaseWear(std::move(InName))
	{
		Color = std::move(InColor);
		WearToColor = InWear;
	}
	void Wear() override
	{
		WearToColor->Wear();
		std::cout << " with color " << Color << "\n";
	}
protected:
	std::string Color;
	std::shared_ptr<BaseWear> WearToColor;
};