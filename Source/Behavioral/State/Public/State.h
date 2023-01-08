#pragma once

#include <memory>
#include <iostream>
#include "TrafficLight.h"
#include "../../../Helpers.h"

class UTrafficLight;

enum class ECurrentColor
{
	RED,
	YELLOW,
	GREEN,
	NONE
};

class ITrafficLightState
{
public:
	ITrafficLightState() = default;
	virtual ~ITrafficLightState() = default;

	virtual void Activate(std::shared_ptr<UTrafficLight> InState) = 0;
	ECurrentColor GetLightColor() const { return CurrentColor; }
	bool TryBreakLight(std::shared_ptr<UTrafficLight> InState) const;

protected:
	ECurrentColor CurrentColor = ECurrentColor::NONE;
};

class URedLightState : public ITrafficLightState
{
public:
	URedLightState() { CurrentColor = ECurrentColor::RED; }
	virtual ~URedLightState() override = default;

	virtual void Activate(std::shared_ptr<UTrafficLight> InState) override;
};

class UYellowLightState : public ITrafficLightState
{
public:
	UYellowLightState() { CurrentColor = ECurrentColor::YELLOW; }
	virtual ~UYellowLightState() override = default;

	virtual void Activate(std::shared_ptr<UTrafficLight> InState) override;
};

class UGreenLightState : public ITrafficLightState
{
public:
	UGreenLightState() { CurrentColor = ECurrentColor::GREEN; }
	virtual ~UGreenLightState() override = default;

	virtual void Activate(std::shared_ptr<UTrafficLight> InState) override;
};

class UBrokenLightState : public ITrafficLightState
{
public:
	UBrokenLightState() = default;
	virtual ~UBrokenLightState() override = default;

	virtual void Activate(std::shared_ptr<UTrafficLight> InState) override;
};