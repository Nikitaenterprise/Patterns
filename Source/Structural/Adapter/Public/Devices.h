#pragma once

#include <memory>
#include "Socket.h"

class Device
{
public:
	Device() = default;
	virtual ~Device() = default;

	virtual void WhantToCharge()
	{
		Charge(DeviceSocket);
	}

	virtual void Charge(const std::unique_ptr<Socket>& InDeviceSocket) = 0;
	const std::unique_ptr<Socket>& GetSocket() const { return DeviceSocket; }

protected:
	std::unique_ptr<Socket> DeviceSocket = nullptr;
};


class EuropeDevice : public Device
{
public:
	EuropeDevice()
	{
		DeviceSocket = std::make_unique<Socket>(EUSocket());
	}
	virtual ~EuropeDevice() override = default;

	void Charge(const std::unique_ptr<Socket>& InDeviceSocket) override
	{
		InDeviceSocket->Connect();
		ChargingEuropeDevice();
		InDeviceSocket->Disconnect();
	}

	virtual void ChargingEuropeDevice()
	{
		std::cout << "Charging Europe device through " << DeviceSocket->Standard->ToString() << "\n";
	}
};


class UnitedStatesDevice : public Device
{
public:
	UnitedStatesDevice()
	{
		DeviceSocket = std::make_unique<Socket>(USASocket());
	}
	virtual ~UnitedStatesDevice() override = default;

	void Charge(const std::unique_ptr<Socket>& InDeviceSocket) override
	{
		InDeviceSocket->Connect();
		ChargingUnitedStatesDevice();
		InDeviceSocket->Disconnect();
	}

	virtual void ChargingUnitedStatesDevice()
	{
		std::cout << "Charging United States device through " << DeviceSocket->Standard->ToString() << "\n";
	}
};