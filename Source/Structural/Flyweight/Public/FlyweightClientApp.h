#pragma once

#include <vector>
#include <memory>
#include"Flyweight.h"

class FlyweightClientApp
{
public:
	FlyweightClientApp()
	{
		auto GetCoords = []()
		{
			return static_cast<float>(rand()) / 1000.f;
		};

		std::vector<std::unique_ptr<Building>> Buildings;

		// Using push_back instead of initializer_list because of 
		// init_list tries to use copy constructor for unique_ptr
		// and it's deleted
		Buildings.push_back(std::unique_ptr<Building>( new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Tall building")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
			
		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Small building")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
	

		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Wide building")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
		
		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Skyscrapper")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
		
		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Skyscrapper")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
		
		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Skyscrapper")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));
			
		Buildings.push_back(std::unique_ptr<Building>(new Building{
			std::unique_ptr<HeavyData>(new HeavyData("Skyscrapper")),
			std::unique_ptr<LightData>(new LightData(GetCoords(), GetCoords(), GetCoords()))}));

		for (const auto& B : Buildings)
		{
			B->Draw();
		}
	}
};