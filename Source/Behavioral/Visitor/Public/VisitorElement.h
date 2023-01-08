#pragma once

#include <memory>
#include "Visitor.h"

class IVisitor;

class IVisitorElement
{
public:
	IVisitorElement() = default;
	virtual ~IVisitorElement() = default;

	virtual void AcceptVisitor(const std::unique_ptr<IVisitor>& InVisitor) const = 0;
	virtual const std::string& GetData() const { return Data; }

protected:
	std::string Data;
};

class UFirstVisitorElement : public IVisitorElement
{
public:
	UFirstVisitorElement()
	{
		Data = "UFirstVisitorElement";
	}
	virtual ~UFirstVisitorElement() override = default;

	virtual void AcceptVisitor(const std::unique_ptr<IVisitor>& InVisitor) const override;
};

class USecondVisitorElement : public IVisitorElement
{
public:
	USecondVisitorElement()
	{
		Data = "USecondVisitorElement";
	}
	virtual ~USecondVisitorElement() override = default;

	virtual void AcceptVisitor(const std::unique_ptr<IVisitor>& InVisitor) const override;
};