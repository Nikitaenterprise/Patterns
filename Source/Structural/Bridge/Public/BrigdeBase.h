#pragma once

#include <iostream>
#include <ostream>
#include <map>
#include <string>
#include <vector>

class Road
{
public:
	class Line
	{
	public:
		enum class ELineType
		{
			CAR,
			METRO,
			TRAIN,
			PEDESTRIAN
		}; 

		Line(ELineType InLineType, bool bInHasLights, bool bInIsForEmergency)
			: LineType(InLineType), bHasLights(bInHasLights), bIsForEmergency(bInIsForEmergency) 
		{}

		ELineType GetLineType() const { return LineType; }
		bool HasLights() const { return bHasLights; }
		bool IsForEmergency() const { return bIsForEmergency; }
		bool IsClosed() const { return bIsClosed; }

	protected:
		bool bHasLights = false;
		bool bIsForEmergency = false;
		bool bIsClosed = false;
		ELineType LineType = ELineType::CAR;

	private:
		friend class Road;
	};

	Road(std::vector<Line>&& InLines) { Lines = InLines; }
	size_t GetLinesNumber() const { return Lines.size(); }
	std::vector<Line>& GetLines() { return Lines; }

protected:
	std::vector<Line> Lines;

private:
	friend class BridgeBase;
};

std::ostream& operator<<(std::ostream& out, const Road::Line::ELineType LineType)
{
	static std::map<Road::Line::ELineType, std::string> Names;
	if (Names.size() == 0)
	{
#define ADD_NAME(Name) Names[Name] = #Name;
		ADD_NAME(Road::Line::ELineType::CAR);
		ADD_NAME(Road::Line::ELineType::METRO);
		ADD_NAME(Road::Line::ELineType::TRAIN);
		ADD_NAME(Road::Line::ELineType::PEDESTRIAN);
#undef ADD_NAME
	}
	return out << Names[LineType];
}

class BridgeBase
{
public:
	enum class EBridgeType
	{
		BEAM,
		TRUSS,
		CANTILEVER,
		ARCH,
		SUSPENSION,
		CABLE_STAYED,

		NONE
	};

	bool IsOpen() const { return bIsOpen; }
	void OpenBridge() { bIsOpen = true; }
	void CloseBridge() { bIsOpen = false; }
	bool IsOneWay() const { return bIsOneWay; }
	std::vector<Road>& GetRoads() { return Roads; }
	
	bool HasLine(const Road::Line::ELineType InLineType)
	{
		for (const auto& ThisRoad : Roads)
		{
			for (const auto& ThisLine : ThisRoad.Lines)
			{
				if (ThisLine.GetLineType() == InLineType)
				{
					return true;
				}
			}
		}
		return false;
	}

protected:
	bool bIsOpen = false;
	bool bIsOneWay = false;

	std::vector<Road> Roads;
	EBridgeType BridgeType = EBridgeType::NONE;
};

class PatonaBridge : public BridgeBase
{
public:
	PatonaBridge() : BridgeBase()
	{
		BridgeType = BridgeBase::EBridgeType::BEAM;
		bIsOneWay = false;
		Roads = { 
			std::move(std::vector<Road::Line>{
				Road::Line(Road::Line::ELineType::PEDESTRIAN, true, false),
				Road::Line(Road::Line::ELineType::CAR, true, true),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, true, true),
				Road::Line(Road::Line::ELineType::PEDESTRIAN, true, false)
		})};
	}
};

class SouthBridge : public BridgeBase
{
public:
	SouthBridge() : BridgeBase()
	{
		BridgeType = BridgeBase::EBridgeType::CABLE_STAYED;
		bIsOneWay = false;
		Roads = {
			std::move(std::vector<Road::Line>{
				Road::Line(Road::Line::ELineType::PEDESTRIAN, true, false),
				Road::Line(Road::Line::ELineType::CAR, true, true),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::METRO, true, false),
				Road::Line(Road::Line::ELineType::METRO, true, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, false, false),
				Road::Line(Road::Line::ELineType::CAR, true, true),
				Road::Line(Road::Line::ELineType::PEDESTRIAN, true, false)
		})};
	}
};