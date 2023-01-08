#pragma once

#include <random>
#include <string>
#include <memory>

namespace Helpers
{
    size_t GetRandom(size_t Start, size_t End);
    std::string GenerateGUID();

	template<typename Item>
	class Function;
	template<typename ReturnValue, typename ...Arguments>
	class Function<ReturnValue(Arguments...)>
	{
	public:
		Function() {}

		template <typename FunctionObject>
		Function(FunctionObject InFunc) : Callable(std::make_unique<CallableImplementation<FunctionObject>>(std::move(InFunc))) {}

		template <typename FunctionObject>
		Function(Function& OtherFunction)
		{
			Callable(std::move(OtherFunction.Callable));
		}

		ReturnValue operator()(Arguments... InArgs)
		{
			return Callable->Call(InArgs...);
		}

		operator bool()
		{
			if (Callable.get())
			{
				return true;
			}
			return false;
		}

	private:
		struct CallableInterface
		{
			virtual ReturnValue Call(Arguments...) = 0;
			virtual ~CallableInterface() = default;
		};

		template <typename CallableType>
		struct CallableImplementation : public CallableInterface
		{
			CallableImplementation(CallableType InCallableType) : Callable(std::move(InCallableType)) {}
			virtual ~CallableImplementation() override = default;
			virtual ReturnValue Call(Arguments... InArgs) override { return Callable(InArgs...); }

			CallableType Callable;
		};

		std::unique_ptr<CallableInterface> Callable;
	};
}