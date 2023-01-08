#pragma once

#include <vector>
#include <map>
#include <memory>
#include <string>
#include <iostream>
#include "Creational/Singleton/Public/Singleton.h"

struct HeavyData
{
	HeavyData(const std::string& InResource)
	{
		GraphicResource = InResource;
		constexpr size_t Size = 10000;
		Data.reserve(Size);
		for (size_t i = 0; i < Size; i++)
		{
			Data.push_back(rand());
		}
	}
	std::string GraphicResource;
	std::vector<int> Data;
};

struct LightData
{
	LightData(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {};
	float X;
	float Y;
	float Z;
};

class BuildingFlyweight
{
public:
	BuildingFlyweight() = delete;
	BuildingFlyweight(std::unique_ptr<HeavyData>&& InHeavyData)
	{
		Data = std::move(InHeavyData);
	}

	void Draw() const
	{
		printf("Drawing %s flyweight\n", Data->GraphicResource.c_str());
	}

	const HeavyData* const GetData() const { return Data.get(); }

protected:
	std::unique_ptr<HeavyData> Data;
};

class BuildingFactory
{
public:
	void AddToCache(std::shared_ptr<BuildingFlyweight> InBuildingFlyweight)
	{
		const std::string& Id = InBuildingFlyweight->GetData()->GraphicResource;
		if (BuildingsCache.contains(Id) == false)
		{
			BuildingsCache.emplace(Id, InBuildingFlyweight);
		}
	}

	std::shared_ptr<BuildingFlyweight> GetBuilding(std::unique_ptr<HeavyData>&& InHeavyData)
	{
		const std::string& Id = InHeavyData->GraphicResource;
		if (BuildingsCache.contains(Id) == false)
		{
			BuildingsCache.emplace(Id, std::shared_ptr<BuildingFlyweight>(new BuildingFlyweight(std::move(InHeavyData))));
		}
		return BuildingsCache[Id];
	}

protected:
	std::map<std::string, std::shared_ptr<BuildingFlyweight>> BuildingsCache;
};

class Building
{
public:
	Building(std::unique_ptr<HeavyData>&& InHeavyData, std::unique_ptr<LightData>&& InLightData)
	{
		Data = std::move(InLightData);
		Flyweight = Singleton<BuildingFactory>::GetObject()->GetBuilding(std::move(InHeavyData));
	}

	void Draw() const
	{
		printf("Drawing building at X = %f, Y = %f, Z = %f\n", Data->X, Data->Y, Data->Z);
		Flyweight->Draw();
	}

protected:
	std::unique_ptr<LightData> Data;
	std::shared_ptr<BuildingFlyweight> Flyweight;
};