#pragma once

#include "../../../ForTests.h"
#include "AbstractFactory.h"
#include "../../Singleton/Public/Singleton.h"

class AbstractFactoryClientApp : public ForTests
{
public:
	AbstractFactoryClientApp() = delete;
	explicit AbstractFactoryClientApp(EPlatform CurrentPlatform) : ForTests(CurrentPlatform)
	{
		using namespace AbstractFactory;

		switch (CurrentPlatform)
		{
		case EPlatform::Windows:
		{
			if (const auto& Factory = Singleton<UWindowsWidgetFactory>::GetObject())
			{
				Factory->CreateWidget();
			}
			break;
		}
		case EPlatform::Mac:
		{
			if (const auto& Factory = Singleton<UMacWidgetFactory>::GetObject())
			{
				Factory->CreateWidget();
			}
			break;
		}
		default:
			break;
		}
	}
};

