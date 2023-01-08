#pragma once

#include <memory>
#include <iostream>
#include "VisitorElement.h"

class IVisitorElement;

class IVisitor
{
public:
	IVisitor() = default;
	virtual ~IVisitor() = default;

	virtual void VisitFirst(const IVisitorElement& InElement) = 0;
	virtual void VisitSecond(const IVisitorElement& InElement) = 0;
};

class UVisitor : public IVisitor
{
public:
	UVisitor() = default;
	virtual ~UVisitor() = default;

	virtual void VisitFirst(const IVisitorElement& InElement) override;
	virtual void VisitSecond(const IVisitorElement& InElement) override;
};