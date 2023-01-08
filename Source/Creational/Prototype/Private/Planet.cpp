#include "../Public/Planet.h"

UPlanet::UPlanet()
{
	Name = "NONE";
}

UPlanet::UPlanet(const UPlanet& ThatPlanet)
{
	this->Name = ThatPlanet.Name;
	this->bHasRings = ThatPlanet.bHasRings;
	this->Mass = ThatPlanet.Mass;
	this->Population = ThatPlanet.Population;
	this->Radius = ThatPlanet.Radius;
	
	this->Sattelites.reserve(ThatPlanet.Sattelites.size());
	for (const auto& ThatSattelite : ThatPlanet.Sattelites)
	{
		this->Sattelites.push_back(ThatSattelite);
	}
}

UPlanet::UPlanet(const std::string& InName, bool bInHasRings, int InRadius, int InPopulation, float InMass) :
	Name(InName), bHasRings(bInHasRings), Radius(InRadius), Population(InPopulation), Mass(InMass)
{
}

void UPlanet::AddSattelites(std::vector<std::string>&& InSattelites)
{
	Sattelites = std::move(InSattelites);
}

std::unique_ptr<IPrototypeBase> UPlanet::Clone()
{
	std::unique_ptr<IPrototypeBase> Result;
	Result.reset(new UPlanet(*this));
	return Result;
}
