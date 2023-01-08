#pragma once

#include <memory>
#include "Proxy.h"

class ProxyClientApp
{
public:
	ProxyClientApp()
	{
		std::unique_ptr<ITelescope> Telescope = std::make_unique<ProxyTelescope>(WantToLookAt::SEA);
		Telescope->LookAt();
		std::unique_ptr<ITelescope> WrongTelescope = std::make_unique<ProxyTelescope>(WantToLookAt::BUILDING);
		WrongTelescope->LookAt();
	}
};