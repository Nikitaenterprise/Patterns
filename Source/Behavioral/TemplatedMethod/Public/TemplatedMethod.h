#pragma once

#include <memory>
#include <iostream>

class ITemplatedMethod
{
public:
	ITemplatedMethod() = default;
	virtual ~ITemplatedMethod() = default;

	const std::string& Run()
	{
		StepOne();
		if (PreStepTwo())
		{
			StepTwo();
			return PastStepTwo();
		}
		StepThree();
		return Result;
	}

protected:
	virtual void StepOne() = 0;
	virtual bool PreStepTwo() = 0;
	virtual void StepTwo() = 0;
	virtual const std::string& PastStepTwo() = 0;
	void StepThree()
	{
		Result += "StepThree\n";
	}

	std::string Result;
};

class UFirstTemplatedMethod : public ITemplatedMethod
{
public:
	UFirstTemplatedMethod() = default;
	virtual ~UFirstTemplatedMethod() override = default;

protected:
	virtual void StepOne() override
	{
		Result = "StepOne\n";
	}
	virtual bool PreStepTwo() override
	{
		Result += "PreStepTwo\n";
		return true;
	}
	virtual void StepTwo() override
	{
		Result += "StepTwo\n";
	}
	virtual std::string& PastStepTwo() override
	{
		Result += "PastStepTwo\n";
		return Result;
	}
};

class USecondTemplatedMethod : public ITemplatedMethod
{
public:
	USecondTemplatedMethod() = default;
	virtual ~USecondTemplatedMethod() override = default;

protected:
	virtual void StepOne() override
	{
		Result = "StepOne\n";
	}
	virtual bool PreStepTwo() override
	{
		Result += "PreStepTwo\n";
		return false;
	}
	virtual void StepTwo() override {}
	virtual std::string& PastStepTwo() override { return Result; }
};