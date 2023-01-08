#pragma once

#include <iostream>
#include <memory>

class ESocketType
{
public:
	virtual const std::string& ToString() {	return Name; }

protected:
	std::string Name = "NONE";
};

#define SOCKET_TYPE(SocketType, Numeration)								\
	class SocketType : public ESocketType								\
	{																	\
	public:																\
		SocketType() { Name = #SocketType; }							\
		static const int SocketType_Member = Numeration;				\
	};																	\

SOCKET_TYPE(EU, 0)
SOCKET_TYPE(USA, 1)

#undef SOCKET_TYPE

class Socket
{
public:
	Socket() {}
	
	virtual void Connect()
	{
		std::cout << "Connected to " << Standard->ToString() << "\n";
	}

	virtual void Disconnect()
	{
		std::cout << "Disconnected from " << Standard->ToString() << "\n";
	}

	std::unique_ptr<ESocketType> Standard = nullptr;
};

class EUSocket : public Socket
{
public:
	EUSocket() : Socket()
	{
		Standard = std::unique_ptr<ESocketType>(new EU());
	}
};

class USASocket : public Socket
{
public:
	USASocket() : Socket()
	{
		Standard = std::unique_ptr<ESocketType>(new USA());
	}
};