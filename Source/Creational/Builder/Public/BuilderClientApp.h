#pragma once

#include <memory>
#include <iostream>
#include "../../../ForTests.h"
#include "../../Singleton/Public/Singleton.h"
#include "StringDirector.h"
#include "StringBuilder.h"

class BuilderClientApp : public ForTests
{
public:
	BuilderClientApp() = delete;
	explicit BuilderClientApp(EPlatform InCurrentPlatform) : ForTests(InCurrentPlatform)
	{
		switch (InCurrentPlatform)
		{
		case EPlatform::Windows:
		{
			const auto& Builder = Singleton<UStringBuilderWithAts>::GetObject();
			const auto& Director = std::make_shared<UStringDirector>(Builder);
			std::cout << Builder->GetString();
			Director->AdditionalConstruct();
			std::cout << Builder->GetString();
			break;
		}
		case EPlatform::Mac:
		{
			const auto& Builder = Singleton<UStringBuilderWithSlashes>::GetObject();
			const auto& Director = std::make_shared<UStringDirector>(Builder);
			std::cout << Builder->GetString();
			Director->AdditionalConstruct();
			std::cout << Builder->GetString();
			break;
		}
		default:
			break;
		}
	}
};