#pragma once

#include <memory>
#include "../../../Helpers.h"
#include "Observer.h"

class ObserverClientApp
{
public:
	ObserverClientApp()
	{
		std::shared_ptr<ISubscriber> ConcreteSubscriber1;
		ConcreteSubscriber1.reset(new UConcreteSubscriber(Helpers::GenerateGUID()));
		std::shared_ptr<ISubscriber> ConcreteSubscriber2;
		ConcreteSubscriber2.reset(new UConcreteSubscriber(Helpers::GenerateGUID()));
		std::shared_ptr<ISubscriber> ConcreteSubscriber3;
		ConcreteSubscriber3.reset(new UConcreteSubscriber(Helpers::GenerateGUID()));

		std::unique_ptr<UNotifier> Notifier = std::make_unique<UNotifier>();

		Notifier->Register(ConcreteSubscriber1);
		Notifier->Register(ConcreteSubscriber2);
		Notifier->Register(ConcreteSubscriber3);

		Notifier->Notify();

		Notifier->Unsubscribe(ConcreteSubscriber1);

		Notifier->Notify();
	}
};