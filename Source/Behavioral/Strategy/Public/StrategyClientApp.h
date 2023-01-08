#pragma once

#include "StrategyContext.h"
#include "Strategy.h"

class StrategyClientApp
{
public:
	StrategyClientApp()
	{
		auto StrategyContext = std::make_shared<UStrategyContext>();
		
		StrategyContext->SetStrategy(std::unique_ptr<IStrategy>(new UFirstStrategy));
		StrategyContext->ExcecuteStrategy();

		StrategyContext->SetStrategy(std::unique_ptr<IStrategy>(new USecondStrategy));
		StrategyContext->ExcecuteStrategy();
	}
};