#pragma once

#include <string>

class IStringBuilder
{
public:
	IStringBuilder() = default;
	virtual ~IStringBuilder() = default;

	virtual void Flush() { ResultString.clear(); }
	virtual void FirstStep() {};
	virtual void SecondStep() {};
	virtual void ThirdStep() {};
	virtual void PostConstructFlush() {};

	const std::string& GetString() const { return ResultString; }
	std::string& GetStringMutable() { return ResultString; }

protected:
	std::string ResultString;
};

class UStringBuilderWithAts : public IStringBuilder
{
public:
	UStringBuilderWithAts() = default;
	virtual ~UStringBuilderWithAts() override = default;

	void FirstStep() override;
	void SecondStep() override;
	void ThirdStep() override;
	void PostConstructFlush() override;
};

class UStringBuilderWithSlashes : public IStringBuilder
{
public:
	UStringBuilderWithSlashes() = default;
	virtual ~UStringBuilderWithSlashes() override = default;
	void FirstStep() override;
	void SecondStep() override;
	void ThirdStep() override;
};