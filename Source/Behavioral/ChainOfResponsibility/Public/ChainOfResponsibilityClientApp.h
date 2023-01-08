#pragma once

#include <iostream>
#include <memory>
#include "ChainOfResponsibility.h"

class ChainOfResponsibilityClientApp
{
public:
	ChainOfResponsibilityClientApp()
	{
		std::shared_ptr<IWidget> MyButton = std::shared_ptr<IWidget>(new Button(nullptr));
		std::shared_ptr<IWidget> MyInfoButton = std::shared_ptr<IWidget>(new InfoButton(MyButton));
		std::shared_ptr<IWidget> MyOverlay = std::shared_ptr<IWidget>(new Overlay(MyInfoButton));
		std::shared_ptr<IWidget> MySecondOverlay = std::shared_ptr<IWidget>(new Overlay(nullptr));

		std::cout << MyOverlay->Click() << "\n";
		std::cout << MySecondOverlay->Click() << "\n";
	}
};