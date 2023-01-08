#pragma once

#include "Creational/AbstractFactory/Public/AbstractFactoryClientApp.h"
#include "Creational/Builder/Public/BuilderClientApp.h"
#include "Creational/FactoryMethod/Public/FactoryMethodClientApp.h"
#include "Creational/Prototype/Public/PrototypeClientApp.h"
#include "Structural/Adapter/Public/AdapterClientApp.h"
#include "Structural/Bridge/Public/BridgeClientApp.h"
#include "Structural/Composer/Public/ComposerClientApp.h"
#include "Structural/Decorator/Public/DecoratorClientApp.h"
#include "Structural/Facade/Public/Facade.ClientApp.h"
#include "Structural/Flyweight/Public/FlyweightClientApp.h"
#include "Structural/Proxy/Public/ProxyClientApp.h"
#include "Behavioral/ChainOfResponsibility/Public/ChainOfResponsibilityClientApp.h"
#include "Behavioral/Command/Public/CommandClientApp.h"
#include "Behavioral/Interpreter/Public/InterpreterClientApp.h"
#include "Behavioral/Iterator/Public/IteratorClientApp.h"
#include "Behavioral/Mediator/Public/MediatorClientApp.h"
#include "Behavioral/Memento/Public/MementoClientApp.h"
#include "Behavioral/Observer/Public/ObserverClientApp.h"
#include "Behavioral/State/Public/StateClientApp.h"
#include "Behavioral/Strategy/Public/StrategyClientApp.h"
#include "Behavioral/TemplatedMethod/Public/TemplatedMethodClientApp.h"
#include "Behavioral/Visitor/Public/VisitorClientApp.h"

int main()
{
	AbstractFactoryClientApp		App1(EPlatform::Windows);
	BuilderClientApp				App2(EPlatform::Windows);
	FactoryMethodClientApp			App3(EPlatform::Mac);
	PrototypeClientApp				App4;
	AdapterClientApp				App5;
	BridgeClientApp					App6;
	ComposerClientApp				App7;
	DecoratorClientApp				App8;
	FacadeClientApp					App9;
	FlyweightClientApp				App10;
	ProxyClientApp					App11;
	ChainOfResponsibilityClientApp	App12;
	CommandClientApp				App13;
	InterpreterClientApp			App14;
	IteratorClientApp				App15;
	MediatorClientApp				App16;
	MementoClientApp				App17;
	ObserverClientApp				App18;
	StateClientApp					App19;
	StrategyClientApp				App20;
	TemplatedMethodClientApp		App21;
	VisitorClientApp				App22;

	return 0;
}