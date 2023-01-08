#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class IWorkElement
{
public:
	IWorkElement() = delete;
	explicit IWorkElement(const std::string& InName) { Name = InName; }
	virtual ~IWorkElement() = default;

	virtual void DoWork() = 0;
	virtual void AddToDepartment(std::shared_ptr<IWorkElement> InDepartment) = 0;
	virtual void RemoveFormDepartment(std::shared_ptr<IWorkElement> InDepartment) = 0;
	virtual std::vector<std::shared_ptr<IWorkElement>> GetChilds() const { return Childs; }
	virtual std::shared_ptr<IWorkElement> GetComposite() { return nullptr; }

protected:
	std::string Name;
	std::vector<std::shared_ptr<IWorkElement>> Childs;
};

// Workaround for instantiate virual class with shared_ptr
std::shared_ptr<IWorkElement> GetPtr(IWorkElement* InPtr)
{
	std::shared_ptr<IWorkElement> Returnable;
	Returnable.reset(InPtr);
	return Returnable;
}

class Employee : public IWorkElement
{
public:
	Employee() = delete;
	Employee(const std::string& InName) : IWorkElement(InName) {};
	virtual ~Employee() override = default;
	
	void DoWork() override
	{
		std::cout << "Employee " << Name << "is working\n";
	}
	
	// Simulate Add to department
	void AddToDepartment(std::shared_ptr<IWorkElement> InDepartment) 
	{
		if (Childs.size() == 0)
		{
			Childs.push_back(GetPtr(this));
		}
	};
	void RemoveFormDepartment(std::shared_ptr<IWorkElement> InDepartment) {};
};

class Department : public IWorkElement
{
public:
	Department() = delete;
	Department(const std::string& InName) : IWorkElement(InName) {};
	virtual ~Department() override = default;

	void DoWork() override
	{
		std::cout << "Department " << Name << "is working\n";
		for (const auto& Child : Childs)
		{
			Child->DoWork();
		}
	}

	void AddToDepartment(std::shared_ptr<IWorkElement> InDepartment) override
	{
		Childs.push_back(InDepartment);
	}

	void RemoveFormDepartment(std::shared_ptr<IWorkElement> InDepartment) override
	{
		std::vector<std::shared_ptr<IWorkElement>> Temp;
		Temp.reserve(Childs.size());

		for (size_t i = 0; i < Childs.size(); i++)
		{
			Temp[i] = Childs[i];
			if (Childs[i] == InDepartment)
			{
				continue;
			}
		}

		Childs = std::move(Temp);
	}

	std::shared_ptr<IWorkElement> GetComposite() override { return GetPtr(this);	}
};