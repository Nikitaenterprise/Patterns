#pragma once

#include "FactoryMethod.h"

class UFarmBase;

class UFarmCreator : public IFactoryMethod<UFarmBase>
{
public:
	UFarmCreator() = default;
	virtual ~UFarmCreator() override = default;
	void CreateFarm();

protected:
	virtual void Create() = 0;

	std::shared_ptr<UFarmBase> ConcreteFarm = nullptr;
};

class URanchoCreator : public UFarmCreator
{
public:
	URanchoCreator() = default;
	virtual ~URanchoCreator() override = default;

protected:
	void Create() override;
};

class UkrainianFarmCreator : public UFarmCreator
{
public:
	UkrainianFarmCreator() = default;
	virtual ~UkrainianFarmCreator() override = default;

protected:
	void Create() override;
};