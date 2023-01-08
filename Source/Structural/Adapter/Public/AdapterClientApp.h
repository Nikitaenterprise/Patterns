#pragma once

#include "..\Public\Devices.h"
#include "..\Public\Adapter.h"

class AdapterClientApp
{
public:
	AdapterClientApp()
	{
		// For simplicity using raw pointers
		auto* EUDevice = new EuropeDevice();
		EUDevice->WhantToCharge();

		auto* USADevice = new UnitedStatesDevice();
		USADevice->WhantToCharge();

		std::cout << "\n\n\nNow using first adapter\n\n\n";
		auto* FirstAdapter = new EuropeToUSAAdapter(EUDevice);
		FirstAdapter->WhantToCharge();

		std::cout << "\n\n\nNow using second adapter\n\n\n";
		auto* SecondAdapter = new USAToEuropeAdapter();
		SecondAdapter->WhantToCharge();

		delete EUDevice;
		delete USADevice;
		delete FirstAdapter;
		delete SecondAdapter;
	}
};