#pragma once

#include <string>

class UFarmBase
{
public:
	const std::string& GetAnimals() const { return Animals; }

protected:
	std::string Animals;
};

class UUkrainianFarm : public UFarmBase
{
public:
	UUkrainianFarm();
};

class URancho : public UFarmBase
{
public:
	URancho();
};