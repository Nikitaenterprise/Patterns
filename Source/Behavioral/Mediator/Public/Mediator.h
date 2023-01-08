#pragma once

#include <memory>
#include <iostream>

class IComponent;

class IMediator
{
public:
	IMediator() = default;
	virtual ~IMediator() = default;

    virtual void Send(const std::string& InMessage, IComponent& InComponent) = 0;
};

class IComponent
{
public:
    IComponent() = delete;
	IComponent(std::shared_ptr<IMediator> InMediator) : Mediator(std::move(InMediator)) {};
	virtual ~IComponent() = default;

	virtual void Notify(const std::string& InEvent) = 0;

protected:
	std::shared_ptr<IMediator> Mediator;
	std::string Event;
};