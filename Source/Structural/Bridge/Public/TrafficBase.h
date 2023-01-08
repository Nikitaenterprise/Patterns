#pragma once

#include <memory>
#include <iostream>
#include "BrigdeBase.h"

class TrafficControlBase
{
public:
	TrafficControlBase(std::unique_ptr<BridgeBase> InBridge) : Bridge(std::move(InBridge)) {}
	
	void StartTraffic() 
	{ 
		if (Bridge)
		{
			Bridge->OpenBridge();
		}
	}
	
	void StopTraffic()
	{
		if (Bridge)
		{
			Bridge->CloseBridge();
		}
	}

protected:
	std::unique_ptr<BridgeBase> Bridge;
};

class RoadMaintance : public TrafficControlBase
{
public:
	RoadMaintance(std::unique_ptr<BridgeBase> InBridge) : TrafficControlBase(std::move(InBridge)) {}
	void MaintainRoad(bool bLeft = true)
	{
		if (Bridge == nullptr)
		{
			return;
		}

		StartTraffic();

		if (bLeft && Bridge->GetRoads().size() > 0)
		{
			for (Road& ThisRoad : Bridge->GetRoads())
			{
				for (Road::Line& ThisLine : ThisRoad.GetLines())
				{
					std::cout << "Maintaining line " << ThisLine.GetLineType() << std::endl;
				}
			}
		}

		StopTraffic();
	}
};

class LightFixes : public TrafficControlBase
{
public:
	LightFixes(std::unique_ptr<BridgeBase> InBridge) : TrafficControlBase(std::move(InBridge)) {}
	void FixLight()
	{
		if (Bridge == nullptr)
		{
			return;
		}

		StartTraffic();

		if (Bridge->GetRoads().size() > 0)
		{
			for (Road& ThisRoad : Bridge->GetRoads())
			{
				for (Road::Line& ThisLine : ThisRoad.GetLines())
				{
					if (ThisLine.GetLineType() == Road::Line::ELineType::PEDESTRIAN)
					{
						std::cout << "Fixing lights on " << ThisLine.GetLineType() << std::endl;
					}
				}
			}
		}

		StopTraffic();
	}
};