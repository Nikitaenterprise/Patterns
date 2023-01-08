#pragma once

#include <memory>
#include <vector>
#include "Visitor.h"
#include "VisitorElement.h"

class VisitorClientApp
{
public:
	VisitorClientApp()
	{
		auto Visitor = std::unique_ptr<IVisitor>(new UVisitor);
		
		std::vector<std::unique_ptr<IVisitorElement>> Elements;
		Elements.push_back(std::unique_ptr<IVisitorElement>(new UFirstVisitorElement));
		Elements.push_back(std::unique_ptr<IVisitorElement>(new USecondVisitorElement));

		for (const auto& Element : Elements)
		{
			Element->AcceptVisitor(Visitor);
		}
	}
};