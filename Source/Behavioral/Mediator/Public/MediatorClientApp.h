#pragma once

#include <iostream>
#include "Mediator.h"
#include "ConcreteClasses.h"

class MediatorClientApp
{
public:
	MediatorClientApp()
	{
		auto ConcreteMediator = std::make_shared<UConcreteMediator>();
		auto ConcreteComponent1 = std::make_shared<UConcreteComponent1>(ConcreteMediator);
		auto ConcreteComponent2 = std::make_shared<UConcreteComponent2>(ConcreteMediator);
		

		ConcreteMediator->AddComponent(ConcreteComponent1);
		ConcreteMediator->AddComponent(ConcreteComponent2);

		ConcreteComponent1->DoA();
		ConcreteComponent2->DoB();
	}
};