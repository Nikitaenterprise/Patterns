#pragma once

#include "../Public/FarmCreators.h"
#include "../../../ForTests.h"

class FactoryMethodClientApp : public ForTests
{
public:
	FactoryMethodClientApp() = delete;
	explicit FactoryMethodClientApp(EPlatform InCurrentPlatform) : ForTests(InCurrentPlatform)
	{
		switch (InCurrentPlatform)
		{
		case EPlatform::Windows:
		{
			if (const auto& Creator = std::make_shared<UkrainianFarmCreator>())
			{
				Creator->CreateFarm();
			}
			break;
		}
		case EPlatform::Mac:
		{
			if (const auto& Creator = std::make_shared<URanchoCreator>())
			{
				Creator->CreateFarm();
			}
			break;
		}
		default:
			break;
		}
	}
};