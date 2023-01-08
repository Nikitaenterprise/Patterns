#pragma once

#include <map>
#include <string>
#include "Interpreter.h"

class Context
{
public:
	bool Lookup(const std::string& InName) const;
	void Assign(std::shared_ptr<BooleanExpression> InExpression, const bool InValue);

private:
	friend inline std::ostream& operator<<(std::ostream& os, const Context& InContext);

	std::map<std::string, bool> ContextMap;
};

std::ostream& operator<<(std::ostream& os, const Context& InContext)
{
	std::string Result = "Context contains this info: ";
	size_t Counter = 0;
	for (const auto& Pair : InContext.ContextMap)
	{
		Counter++;
		Result += Pair.first;
		Result += " is ";
		Result += Pair.second ? "true" : "false";
		if (Counter == InContext.ContextMap.size())
		{
			break;
		}
		Result += ", ";
	}
	return os << Result;
}