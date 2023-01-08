#include "../Public/Context.h"

bool Context::Lookup(const std::string& InName) const
{
	for (const auto& Pair : ContextMap)
	{
		if (Pair.first == InName)
		{
			return Pair.second;
		}
	}
	return false;
}

void Context::Assign(std::shared_ptr<BooleanExpression> InExpression, const bool InValue)
{
	if (ContextMap.contains(InExpression->GetName()) == false)
	{
		ContextMap.insert({ InExpression->GetName(), InValue });
	}
}