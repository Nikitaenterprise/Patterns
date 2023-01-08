#pragma once

#include <iostream>
#include "TemplatedMethod.h"

class TemplatedMethodClientApp
{
public:
	TemplatedMethodClientApp()
	{
		UFirstTemplatedMethod FirstTemplatedMethod;
		std::cout << FirstTemplatedMethod.Run();

		USecondTemplatedMethod SecondTemplatedMethod;
		std::cout << SecondTemplatedMethod.Run();
	}
};