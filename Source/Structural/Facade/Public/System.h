#pragma once

#include <memory>
#include <iostream>

class SimpleSystem
{
public:
	SimpleSystem() = default;

	float Calculate(float a, float b)
	{
		return a + b;
	}
	
	float GetRandomVariable()
	{
		return static_cast<float>(rand())/100.f;
	}
};

class ComplexSystem
{
public:
	ComplexSystem() = default;

	void DoFirstTask()
	{
		std::cout << "ComplexSystem doing first task\n";
	}

	std::string DoSecondTask()
	{
		return "ComplexSystem returning second task\n";
	}

	void DoThirdTask(float Result)
	{
		std::cout << "ComplexSystem got " << Result << " as a result\n";
	}
};

class Facade
{
public:
	Facade(std::unique_ptr<SimpleSystem>&& InSS, std::unique_ptr<ComplexSystem>&& InCS)
	{
		SS = std::move(InSS);
		CS = std::move(InCS);
	}

	void DoWork()
	{
		std::cout << "Facade is doing work\n";
		float Result = static_cast<float>(SS->Calculate(SS->GetRandomVariable(), SS->GetRandomVariable()));
		std::cout << "Simple system got " << Result << "\n";
		CS->DoFirstTask();
		std::cout << CS->DoSecondTask();
		CS->DoThirdTask(Result);
	}

protected:
	std::unique_ptr<SimpleSystem> SS;
	std::unique_ptr<ComplexSystem> CS;
};