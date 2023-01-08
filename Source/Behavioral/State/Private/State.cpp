#include "../Public/State.h"


bool ITrafficLightState::TryBreakLight(std::shared_ptr<UTrafficLight> InState) const
{
	if (static_cast<bool>(Helpers::GetRandom(0, 1)))
	{
		std::cout << "It seems that light is broken\n";
		InState->ChangeState(std::unique_ptr<ITrafficLightState>(new UBrokenLightState));
		return true;
	}
	return false;
}

void URedLightState::Activate(std::shared_ptr<UTrafficLight> InState)
{
	std::cout << "Red light\n";
	if (TryBreakLight(InState))
	{
		return;
	}
	InState->ChangeState(std::unique_ptr<ITrafficLightState>(new UYellowLightState));
}

void UYellowLightState::Activate(std::shared_ptr<UTrafficLight> InState)
{
	std::cout << "Yellow light\n";
	if (TryBreakLight(InState))
	{
		return;
	}
	InState->ChangeState(std::unique_ptr<ITrafficLightState>(new UGreenLightState));
}

void UGreenLightState::Activate(std::shared_ptr<UTrafficLight> InState)
{
	std::cout << "Green light\n";
	if (TryBreakLight(InState))
	{
		return;
	}
	InState->ChangeState(std::unique_ptr<ITrafficLightState>(new URedLightState));
}

void UBrokenLightState::Activate(std::shared_ptr<UTrafficLight> InState)
{
	std::cout << "Broken light\n";
	switch (static_cast<ECurrentColor>(Helpers::GetRandom(0, static_cast<size_t>(ECurrentColor::GREEN))))
	{
	case ECurrentColor::RED:
		InState->ChangeState(std::make_unique<URedLightState>()); break;
	case ECurrentColor::YELLOW:
		InState->ChangeState(std::make_unique<UYellowLightState>()); break;
	case ECurrentColor::GREEN:
		InState->ChangeState(std::make_unique<UGreenLightState>()); break;
	}
}