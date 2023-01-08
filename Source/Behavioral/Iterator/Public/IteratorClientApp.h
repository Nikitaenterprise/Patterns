#pragma once

#include "Iterator.h"

class IteratorClientApp
{
public:
	IteratorClientApp()
	{
		LinkedList<int> List;
		List.Add(0);
		List.Add(1);
		List.Add(2);
		List.Add(3);
		List.Add(4);

		for (const auto& Element : List)
		{
			std::cout << "Value " << Element << "\n";
		}
		for (size_t i = 0; i < 5; i++)
		{
			std::cout << "Value " << List.At(i) << "\n";
		}
		List.DeleteAt(2);
		std::cout << List;
	}
};