#pragma once

#include "BrigdeBase.h"
#include "TrafficBase.h"

class BridgeClientApp
{
public:
	BridgeClientApp()
	{
		RoadMaintance Maintance(std::unique_ptr<BridgeBase>(new PatonaBridge()));
		Maintance.MaintainRoad();

		LightFixes LightFix(std::unique_ptr<BridgeBase>(new SouthBridge()));
		LightFix.FixLight();
	}
};