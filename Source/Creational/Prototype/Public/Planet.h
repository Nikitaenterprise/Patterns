#pragma once

#include <vector>
#include <string>
#include <memory>

class IPrototypeBase
{
public:
	IPrototypeBase() = default;
	virtual ~IPrototypeBase() = default;

	virtual std::unique_ptr<IPrototypeBase> Clone() = 0;
	virtual const std::string& GetName() const = 0;
};

class UPlanet : public IPrototypeBase
{
public:
	UPlanet();
	UPlanet(const UPlanet& ThatPlanet);
	virtual ~UPlanet() override = default;

	UPlanet
	(
		const std::string& InName,
		bool bInHasRings,
		int InRadius,
		int InPopulation,
		float InMass
	);
	
	void AddSattelites(std::vector<std::string>&& InSattelites);

	virtual std::unique_ptr<IPrototypeBase> Clone() override;
	const std::string& GetName() const override { return Name; }

protected:
	bool bHasRings = false;
	int Radius = 0;
	int Population = 0;
	float Mass = 0.f;
	std::vector<std::string> Sattelites;
	std::string Name;
};