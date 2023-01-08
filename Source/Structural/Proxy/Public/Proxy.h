#pragma once

#include <iostream>
#include <map>
#include <memory>


enum class LookAtType
{
	SKY,
	SEA
};

std::ostream& operator<<(std::ostream& out, const LookAtType InLookAtType)
{
	static std::map<LookAtType, std::string> Names;
	if (Names.size() == 0)
	{
#define ADD_NAME(Name) Names[Name] = #Name;
		ADD_NAME(LookAtType::SKY);
		ADD_NAME(LookAtType::SEA);
#undef ADD_NAME
	}
	return out << Names[InLookAtType];
}

class ITelescope
{
public:
	ITelescope() = default;
	virtual ~ITelescope() = default;
	virtual void LookAt() = 0;
};

class Telescope : public ITelescope
{
public:
	Telescope() = delete;
	Telescope(LookAtType InLookAtType) : Type(InLookAtType) {}
	virtual ~Telescope() = default;

	virtual void LookAt() override
	{
		std::cout << "Real telescope is looking at " << Type << "\n";
	}

protected:
	LookAtType Type;
};

enum class WantToLookAt
{
	SKY,
	BUILDING,
	PERSON,
	SEA
};

class ProxyTelescope : public ITelescope
{
public:
	ProxyTelescope(WantToLookAt InType) : Type(InType) {}
	virtual ~ProxyTelescope() override = default;

	virtual void LookAt() override
	{
		std::cout << "Proxy starts\n";
		switch (Type)
		{
		case WantToLookAt::SKY:
		{
			RealTelescope = std::unique_ptr<Telescope>(new Telescope(LookAtType::SKY));
			RealTelescope->LookAt();
			break;
		}
		case WantToLookAt::BUILDING:
			std::cout << "Proxy stops this operation\n";
			break;
		case WantToLookAt::PERSON:
			std::cout << "Proxy stops this operation\n";
			break;
		case WantToLookAt::SEA:
		{
			RealTelescope = std::unique_ptr<Telescope>(new Telescope(LookAtType::SEA));
			RealTelescope->LookAt();
			break;
		}
		default:
			break;
		}
		std::cout << "Proxy ends\n";
	}

protected:
	WantToLookAt Type;
	std::unique_ptr<Telescope> RealTelescope;
};