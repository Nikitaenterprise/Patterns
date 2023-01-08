#pragma once

#include "Devices.h"

class EuropeToUSAAdapter : public UnitedStatesDevice
{
public:
	EuropeToUSAAdapter(EuropeDevice* InDevice) : Device(InDevice) {}
	virtual ~EuropeToUSAAdapter() override = default;

	void WhantToCharge() override
	{
		const auto& AdapterSocket = std::make_unique<Socket>(USASocket());
		Device->Charge(AdapterSocket);
	}

private:
	EuropeDevice* Device = nullptr;
};

class USAToEuropeAdapter : public EuropeDevice, public UnitedStatesDevice
{
public:
	virtual ~USAToEuropeAdapter() override = default;

	void ChargingEuropeDevice()
	{
		const auto& AdapterSocket = std::make_unique<Socket>(EUSocket());
		UnitedStatesDevice::Charge(AdapterSocket);
	}

	void WhantToCharge() override
	{
		ChargingEuropeDevice();
	}
};