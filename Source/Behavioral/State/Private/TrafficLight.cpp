#include "../Public/TrafficLight.h"

UTrafficLight::UTrafficLight() : CurrentState(std::make_unique<URedLightState>()) {}

void UTrafficLight::ChangeColor()
{
	CurrentState->Activate(shared_from_this());
}

void UTrafficLight::ChangeState(std::unique_ptr<ITrafficLightState> InState)
{
	CurrentState = std::move(InState);
}