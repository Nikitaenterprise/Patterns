#include "../Public/Registry.h"

void UPlanetsRegistry::AddToRegistry(std::shared_ptr<UPlanet> ItemToAdd)
{
	if (IsContainedInRegistry(ItemToAdd->GetName()))
	{
		return;
	}
	std::unique_ptr<UPlanet> PutToRegistry;
	PutToRegistry.reset(static_cast<UPlanet*>(ItemToAdd->Clone().release()));
	Registry.insert({ ItemToAdd->GetName(), std::move(PutToRegistry) });
}

std::shared_ptr<UPlanet> UPlanetsRegistry::GetFromRegistry(const std::string& Name)
{
	if (IsContainedInRegistry(Name) == false)
	{
		return nullptr;
	}
	auto Copy = Registry[Name]->Clone();
	return std::shared_ptr<UPlanet>(static_cast<UPlanet*>(Copy.release()));
}

bool UPlanetsRegistry::IsContainedInRegistry(const std::string& Name)
{
	return Registry.contains(Name) && Registry[Name].get();
}
