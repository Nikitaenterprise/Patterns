#pragma once

#include "Memento.h"
#include <iostream>

class MementoClientApp
{
public:
	MementoClientApp()
	{
		auto Originator = std::make_unique<UOriginator>(100);
		auto CopiedOriginator = std::make_unique<UOriginator>(50);
		std::cout << "Original value " << Originator->GetData() << "\n";
		auto Memento = Originator->Save();
		Originator->SetData(200);
		std::cout << "Changed value " << Originator->GetData() << "\n";
		Originator->Restore(Memento);
		CopiedOriginator->Restore(Memento);
		std::cout << "Restored value " << Originator->GetData() << "\n";
		std::cout << "CopiedOriginator Restored value " << CopiedOriginator->GetData() << "\n";
	}
};