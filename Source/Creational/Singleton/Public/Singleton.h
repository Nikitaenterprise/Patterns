#pragma once

#include <cassert>
#include <memory>

template<typename T>
class Singleton
{
public:
	static std::shared_ptr<T> GetObject();

protected:
	Singleton() {};
	Singleton(const Singleton&) = default;
	Singleton(Singleton&&) = default;
	Singleton& operator=(const Singleton&) = default;
	Singleton& operator=(Singleton&&) = default;

private:
	// With c++17
	static inline std::unique_ptr<Singleton<T>> Instance = nullptr;
	static inline std::shared_ptr<T> Object = nullptr;

	// Without c++17
	// static Singleton<T>* Instance;
	// static T* Object;
};

// Without c++17
// template<typename T>
// Singleton<T>* Singleton<T>::Instance = nullptr;
// 
// template<typename T>
// T* Singleton<T>::Object = nullptr;

template<typename T>
std::shared_ptr<T> Singleton<T>::GetObject()
{
	if (Instance == nullptr && Object == nullptr)
	{
		Instance = std::unique_ptr<Singleton<T>>(new Singleton<T>());
		Object = std::shared_ptr<T>(new T());
	}
	else if (Instance == nullptr || Object == nullptr)
	{
		assert(false && "One of the singleton fields are not nullptr");
	}
	return Object;
}