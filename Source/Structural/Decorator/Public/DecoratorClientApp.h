#pragma once

#include "Clothing.h"

class DecoratorClientApp
{
public:
	DecoratorClientApp()
	{
		std::unique_ptr<BaseWear> FirstWear;
		FirstWear.reset(new TopWear("my beautiful wear"));
		FirstWear->Wear();

		std::unique_ptr<BaseWear> SecondWear;
		SecondWear.reset(new ColoredWear("coloring wear", "red", std::shared_ptr<BaseWear>(FirstWear.release())));
		SecondWear->Wear();
	}
};