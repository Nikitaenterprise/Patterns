#include "../Public/FarmCreators.h"
#include "../Public/Farm.h"
#include <iostream>

void UFarmCreator::CreateFarm()
{
	Create();
	if (ConcreteFarm)
	{
		std::cout << ConcreteFarm->GetAnimals() << std::endl;
	}
}

void URanchoCreator::Create()
{
	ConcreteFarm = std::make_shared<URancho>();
}

void UkrainianFarmCreator::Create()
{
	ConcreteFarm = std::make_shared<UUkrainianFarm>();
}
