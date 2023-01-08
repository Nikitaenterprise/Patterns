#pragma once

#include <memory>
#include <iostream>
#include "StrategyContext.h"

class UStrategyContext;

class IStrategy
{
public:
	IStrategy() = default;
	virtual ~IStrategy() = default;

	virtual void ExcecuteStrategy(std::shared_ptr<UStrategyContext> InContext) = 0;
};

class UFirstStrategy : public IStrategy
{
public:
	UFirstStrategy() = default;
	virtual ~UFirstStrategy() override = default;

	virtual void ExcecuteStrategy(std::shared_ptr<UStrategyContext> InContext)
	{
		std::cout << "First strategy is doing some work\n";
	}
};

class USecondStrategy : public IStrategy
{
public:
	USecondStrategy() = default;
	virtual ~USecondStrategy() override = default;

	virtual void ExcecuteStrategy(std::shared_ptr<UStrategyContext> InContext)
	{
		std::cout << "Second strategy is doing some work\n";
		DoComplicatedWork();
	}

protected:
	void DoComplicatedWork()
	{
		std::cout << "Second strategy is doing more work\n";
	}
};