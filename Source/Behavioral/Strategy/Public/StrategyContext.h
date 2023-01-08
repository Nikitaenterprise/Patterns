#pragma once

#include <memory>
#include "Strategy.h"

class IStrategy;

class UStrategyContext : public std::enable_shared_from_this<UStrategyContext>
{
public:
	UStrategyContext() = default;

	void SetStrategy(std::unique_ptr<IStrategy> InStrategy)
	{
		Strategy = std::move(InStrategy);
	}
	void ExcecuteStrategy()
	{
		Strategy->ExcecuteStrategy(shared_from_this());
	}

private:
	std::unique_ptr<IStrategy> Strategy;
};