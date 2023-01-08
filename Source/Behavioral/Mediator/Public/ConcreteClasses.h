#pragma once

#include "Mediator.h"
#include <string>
#include <iostream>
#include <memory>
#include <vector>

class UConcreteMediator : public IMediator
{
public:
    UConcreteMediator() = default;
    virtual ~UConcreteMediator() override = default;

    void AddComponent(std::shared_ptr<IComponent> InComponent)
    {
        Components.push_back(std::move(InComponent));
    }

    void Send(const std::string& InMessage, IComponent& InComponent) override
    {
        for (const auto& Component : Components)
        {
            if (Component.get() != &InComponent)
            {
                Component->Notify(InMessage);
            }
        }
        /*if (InComponent == Component1)
        {
            Component2->Notify(InMessage);
        }
        else
        {
            Component1->Notify(InMessage);
        }*/
    }

private:
    std::vector<std::shared_ptr<IComponent>> Components;
   /* std::shared_ptr<IComponent> Component1;
    std::shared_ptr<IComponent> Component2;*/
};

class UConcreteComponent1 : public IComponent
{
public:
    UConcreteComponent1() = delete;
    UConcreteComponent1(std::shared_ptr<IMediator> InMediator) : IComponent(InMediator) {}
    virtual ~UConcreteComponent1() override = default;

    void Notify(const std::string& InMessage) override
    {
        std::cout << "Component 1 gets message: " << InMessage << std::endl;
    }

    void DoA()
    {
        Mediator->Send("A", *this);
    }
};

class UConcreteComponent2 : public IComponent
{
public:
    UConcreteComponent2() = delete;
    UConcreteComponent2(std::shared_ptr<IMediator> InMediator) : IComponent(InMediator) {}
    virtual ~UConcreteComponent2() override = default;

    void Notify(const std::string& InMessage) override
    {
        std::cout << "Component 2 gets message: " << InMessage << std::endl;
    }

    void DoB()
    {
        Mediator->Send("B", *this);
    }
};