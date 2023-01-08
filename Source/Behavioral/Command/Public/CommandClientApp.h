#pragma once

#include "ButtonWithCommand.h"
#include "Command.h"
#include "../../../Helpers.h"
#include <memory>
#include <functional>
#include <iostream>

class CommandClientApp
{
public:
	CommandClientApp()
	{
		// Test my Func
		auto Func = []() {std::cout << "AAAAAAAAAAAAAAAA\n"; return 10; };
		Helpers::Function<int()> FuncHandle;
		FuncHandle = Func;
		std::cout << FuncHandle() << std::endl;
		// End test

		auto MyButton = std::unique_ptr<ButtonWithSimpleCommand>(new ButtonWithSimpleCommand());
		MyButton->BindOnClick().Bind([]()->void
			{
				std::cout << "Doing work after click\n";
			});
		MyButton->Click();

		auto MySecondButton = std::unique_ptr<ButtonWithArgumentsCommand>(new ButtonWithArgumentsCommand());
		MySecondButton->BindOnClick().Bind([](const std::string& InStr) 
			{ 
				std::cout << "ComplexClick with string : " << InStr << "\n";
			});
		MySecondButton->BindOnDrag().Bind([](const std::vector<int>& InVec) 
			{
				std::cout << "ComplexDrag with vector : ";
				for (int Element : InVec)
				{
					std::cout << Element << " ";
				}
				std::cout << "\n";
			});
		MySecondButton->Click();
		MySecondButton->Drag();
	}
};