#pragma once

#include <memory>
#include "Company.h"

class ComposerClientApp
{
public:
	ComposerClientApp()
	{
		std::cout << "LOL forget to type space between name and 'is' and now everyone are from Latvia\n";
		Department* ArtDepartment = new Department("ArtDepartment");
		Department* QADepartment = new Department("QADepartment");
		Department* CppDepartment = new Department("CppDepartment");

		CppDepartment->AddToDepartment(GetPtr(new Employee("Berezovsky")));
		CppDepartment->AddToDepartment(GetPtr(new Employee("Koloskov")));
		CppDepartment->AddToDepartment(GetPtr(new Employee("Nikita")));

		QADepartment->AddToDepartment(GetPtr(new Employee("Aiupov")));
		QADepartment->AddToDepartment(GetPtr(new Employee("Liulin")));

		ArtDepartment->AddToDepartment(GetPtr(new Employee("Denys")));
		ArtDepartment->AddToDepartment(GetPtr(new Employee("Artem")));

		Department PingleStudio("PingleStudio");
		PingleStudio.AddToDepartment(GetPtr(ArtDepartment));
		PingleStudio.AddToDepartment(GetPtr(QADepartment));
		PingleStudio.AddToDepartment(GetPtr(CppDepartment));

		PingleStudio.DoWork();
	}
};