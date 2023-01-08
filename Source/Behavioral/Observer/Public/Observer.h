#pragma once

#include <memory>
#include <map>

class ISubscriber
{
public:
	ISubscriber() = default;
	virtual ~ISubscriber() = default;

	virtual void Update() = 0;
	const std::string& GetGUID() const { return GUID; }

protected:
	std::string GUID = "NONE";
};

class UConcreteSubscriber : public ISubscriber
{
public:
	UConcreteSubscriber() = delete;
	UConcreteSubscriber(const std::string& InGUID) : ISubscriber() 
	{
		GUID = InGUID; 
		std::cout << "Creating concrete subscriber with GUID " << GUID << "\n";
	}
	virtual ~UConcreteSubscriber() override = default;

	virtual void Update() override
	{
		std::cout << "Updating subscriber with GUID " << GUID << "\n";
	}
};

class UNotifier
{
public:
	UNotifier() = default;

	bool Register(std::shared_ptr<ISubscriber> InSubscriber)
	{
		if (ContainsSubscriber(InSubscriber))
		{
			return false;
		}
		Subscribers.insert({ InSubscriber->GetGUID(), InSubscriber });
		std::cout << "GUID " << InSubscriber->GetGUID() << " is registred\n";
		return true;
	}

	bool Unsubscribe(std::shared_ptr<ISubscriber> InSubscriber)
	{
		if (ContainsSubscriber(InSubscriber) == false)
		{
			return false;
		}
		Subscribers.erase(InSubscriber->GetGUID());
		std::cout << "GUID " << InSubscriber->GetGUID() << " is unregistred\n";
		return true;
	}

	void Notify()
	{
		if (Subscribers.empty())
		{
			return;
		}

		for (const auto& Pair : Subscribers)
		{
			if (Pair.second)
			{
				Pair.second->Update();
			}
		}
	}

private:
	bool ContainsSubscriber(std::shared_ptr<ISubscriber> InSubscriber)
	{
		if (Subscribers.empty())
		{
			return false;
		}

		if (InSubscriber == nullptr)
		{
			return false;
		}

		return Subscribers.contains(InSubscriber->GetGUID());
	}

	std::map<std::string, std::shared_ptr<ISubscriber>> Subscribers;
};