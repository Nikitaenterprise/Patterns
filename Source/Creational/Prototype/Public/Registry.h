#pragma once

#include <memory>
#include <map>
#include <string>
#include <utility>
#include "Planet.h"

class UPlanet;
class IPrototypeBase;

template <typename Item, typename = std::enable_if<std::is_base_of<IPrototypeBase, Item>::value>::type>
class IRegistryBase
{
public:
	IRegistryBase() = default;
	virtual ~IRegistryBase() = default;

	virtual void AddToRegistry(std::shared_ptr<Item> ItemToAdd) = 0;
	virtual std::shared_ptr<Item> GetFromRegistry(const std::string& Name) = 0;
	virtual bool IsContainedInRegistry(const std::string& Name) = 0;

protected:
	std::map<std::string, std::unique_ptr<Item>> Registry;
};

class UPlanetsRegistry : public IRegistryBase<UPlanet>
{
public:
	UPlanetsRegistry() = default;
	virtual	~UPlanetsRegistry() override = default;

	void AddToRegistry(std::shared_ptr<UPlanet> ItemToAdd) override;
	std::shared_ptr<UPlanet> GetFromRegistry(const std::string& Name) override;
	bool IsContainedInRegistry(const std::string& Name) override;
};