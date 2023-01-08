#pragma once

#include <memory>
#include "TrafficLight.h"
#include "State.h"

class StateClientApp
{
public:
	StateClientApp()
	{
		auto TrafficLight = std::shared_ptr<UTrafficLight>(new UTrafficLight);
		for (size_t i = 0; i < 10; i++)
		{
			TrafficLight->ChangeColor();
		}
	}
};