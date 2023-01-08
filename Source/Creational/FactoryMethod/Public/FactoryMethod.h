#pragma once

#include <memory>


template <typename Item>
class IFactoryMethod
{
public:
	IFactoryMethod() = default;
	virtual ~IFactoryMethod() = default;
	virtual void CreateConcreteObject();

protected:
	virtual void Create() = 0;

	std::shared_ptr<Item> ConcreteObject = nullptr;
};

template <typename Item>
void IFactoryMethod<Item>::CreateConcreteObject()
{
	Create();
}