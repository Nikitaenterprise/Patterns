#pragma once

#include <memory>

template<typename T>
class TState 
{
public:
	TState() = delete;
	explicit TState(T InData) : Data(InData) {}
	virtual ~TState() = default;

	const T& GetData() const { return Data; }

protected:
	T Data;
};

template <typename StateType>
class UMemento
{
public:
	UMemento() = delete;
	explicit UMemento(std::unique_ptr<StateType> InState) : State(std::move(InState)) {}

	const std::unique_ptr<StateType>& GetState() const { return State; }
private:
	std::unique_ptr<StateType> State;
};

class UOriginator
{
public:
	UOriginator() = delete;
	explicit UOriginator(int InData) : Data(InData) {}
	void SetData(int InData) { Data = InData; }
	int GetData() const { return Data; }
	
	using MemState = TState<int>;
	auto Save() { return std::make_unique<UMemento<MemState>>(std::make_unique<MemState>(Data)); }
	void Restore(const std::unique_ptr<UMemento<MemState>>& InMemento)
	{
		Data = InMemento->GetState()->GetData();
	}

private:
	int Data;
};

