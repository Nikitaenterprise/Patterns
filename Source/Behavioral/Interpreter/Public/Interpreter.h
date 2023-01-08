#pragma once

#include <memory>
#include <map>
#include <iostream>

class Context;

class BooleanExpression
{
public:
	BooleanExpression() = default;
	virtual ~BooleanExpression() = default;

	virtual bool Evaluate(Context& That) = 0;
	virtual std::shared_ptr<BooleanExpression> Replace(const std::string& Input, const BooleanExpression& ThatExpression) = 0;
	virtual std::shared_ptr<BooleanExpression> Copy() const = 0;

	virtual const std::string& GetName() const { return Name; }

protected:
	std::string Name = "None";
};

class VariableExpression : public BooleanExpression
{
public:
	VariableExpression(const std::string& Input) { Name = Input; }
	virtual ~VariableExpression() override = default;

	virtual bool Evaluate(Context& ThatContext) override;
	virtual std::shared_ptr<BooleanExpression> Replace(const std::string& Input, const BooleanExpression& ThatExpression) override;
	virtual std::shared_ptr<BooleanExpression> Copy() const override;
};

class AndExpression : public BooleanExpression
{
public:
	AndExpression(std::shared_ptr<BooleanExpression> InFirst, std::shared_ptr<BooleanExpression> InSecond) : First(InFirst), Second(InSecond) {}
	virtual ~AndExpression() override = default;

	virtual bool Evaluate(Context& That) override;
	virtual std::shared_ptr<BooleanExpression> Replace(const std::string& Input, const BooleanExpression& ThatExpression) override;
	virtual std::shared_ptr<BooleanExpression> Copy() const override;

private:
	std::shared_ptr<BooleanExpression> First;
	std::shared_ptr<BooleanExpression> Second;
};

class OrExpression : public BooleanExpression
{
public:
	OrExpression(std::shared_ptr<BooleanExpression> InFirst, std::shared_ptr<BooleanExpression> InSecond) : First(InFirst), Second(InSecond) {}
	virtual ~OrExpression() override = default;

	virtual bool Evaluate(Context& That) override;
	virtual std::shared_ptr<BooleanExpression> Replace(const std::string& Input, const BooleanExpression& ThatExpression) override;
	virtual std::shared_ptr<BooleanExpression> Copy() const override;

private:
	std::shared_ptr<BooleanExpression> First;
	std::shared_ptr<BooleanExpression> Second;
};

class NotExpression : public BooleanExpression
{
public:
	NotExpression(std::shared_ptr<BooleanExpression> InFirst) : First(InFirst) {}
	virtual ~NotExpression() override = default;

	virtual bool Evaluate(Context& That) override;
	virtual std::shared_ptr<BooleanExpression> Replace(const std::string& Input, const BooleanExpression& ThatExpression) override;
	virtual std::shared_ptr<BooleanExpression> Copy() const override;

private:
	std::shared_ptr<BooleanExpression> First;
};