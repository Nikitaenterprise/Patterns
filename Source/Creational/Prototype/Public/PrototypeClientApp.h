#pragma once

#include "../Public/Registry.h"
#include "../Public/Planet.h"
#include "../../Singleton/Public/Singleton.h"
#include <iostream>
#include <memory>

class PrototypeClientApp
{
public:
	PrototypeClientApp()
	{
		auto Registry = Singleton<UPlanetsRegistry>::GetObject();

		auto Earth = std::shared_ptr<UPlanet>(new UPlanet(
			"Earth",
			false,
			6300,
			8,
			24));
		Earth->AddSattelites({ "Moon" });

		auto Mars = std::shared_ptr<UPlanet>(new UPlanet(
			"Mars",
			false,
			3390,
			0,
			20));
		Earth->AddSattelites({ "Phobos", "Deimos" });

		Registry->AddToRegistry(Earth);
		Registry->AddToRegistry(Mars);

		std::cout << Registry->GetFromRegistry("Earth")->GetName() << "\n";
		std::cout << Registry->GetFromRegistry("Mars")->GetName() << "\n";
	}
};