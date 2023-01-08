#pragma once

#include "Structural/Facade/Public/System.h"

class FacadeClientApp
{
public:
	FacadeClientApp()
	{
		Facade F(std::unique_ptr<SimpleSystem>(new SimpleSystem()), std::unique_ptr<ComplexSystem>(new ComplexSystem));
		F.DoWork();
	}
};