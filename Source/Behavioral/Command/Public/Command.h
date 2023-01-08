#pragma once

#include <memory>
#include <functional>
#include "../../../Helpers.h"


template <typename Item>
class Command;

template <typename ReturnValue, typename ...Arguments>
class Command<ReturnValue(Arguments...)>
{
public:
	Command() {};
	
	void Bind(Helpers::Function<ReturnValue(Arguments...)>&& InHandle)
	{
		Function = std::move(InHandle);
	}
	ReturnValue Excecute(Arguments... InArgs)
	{
		return Function(InArgs...);
	}
	bool IsBinded() const
	{
		return true;
		//return Function ? true : false;
	}

private:
	//std::function<ReturnValue(Args...) Function;
	Helpers::Function<ReturnValue(Arguments...)> Function;
};