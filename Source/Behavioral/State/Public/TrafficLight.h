#pragma once

#include <memory>
#include "State.h"

class ITrafficLightState;

class UTrafficLight : public std::enable_shared_from_this<UTrafficLight>
{
public:
	UTrafficLight();

	void ChangeColor();
	void ChangeState(std::unique_ptr<ITrafficLightState> InState);

private:
	std::unique_ptr<ITrafficLightState> CurrentState;
};