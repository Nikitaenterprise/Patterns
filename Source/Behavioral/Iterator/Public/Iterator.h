#pragma once

#include <iostream>
#include <memory>

template <class Item>
class LinkedList 
{
private:
    class Element
    {
    public:
        Element() = delete;
        Element(Item InData) { Data = InData; }
        Element& operator=(const Element& Other)
        {
            Data = Other.Data;
            return *this;
        }

        Item Data;
        std::shared_ptr<Element> Next = nullptr;
        std::shared_ptr<Element> Previous = nullptr;
    };

public:
    LinkedList() = default;
    ~LinkedList() = default;
    
    void Add(Item InData)
    {
        auto NewElement = std::shared_ptr<Element>(new Element(InData));
        if (NumberOfElementsInList == 0) 
        {
            StartingElement = NewElement;
            CurrentElement = NewElement;
            NumberOfElementsInList++;
            return;
        }
        NewElement->Previous = CurrentElement;
        CurrentElement->Next = NewElement;
        CurrentElement = NewElement;
        NumberOfElementsInList++;
    }
    Element& At(size_t InPosition)
    {
        if (InPosition >= NumberOfElementsInList || InPosition < 0 || StartingElement == nullptr)
        {
            throw std::exception("Out of bounds");
        }
        auto it = begin();
        for (size_t i = 0; i != InPosition; i++) 
        {
            ++it;
        }
        return *it;
    }
    void DeleteAt(size_t InPosition) 
    {
        if (InPosition > NumberOfElementsInList || InPosition < 0 || StartingElement == nullptr)
        {
            throw std::exception("Out of bounds");
        }
        auto it = begin();
        for (size_t i = 0; i != InPosition; i++)
        {
            ++it;
        }
        if (it == begin())
        {
            StartingElement = it->Next;
        }
        if (it->Next)
        {
            it->Next->Previous = it->Previous;
        }
        if (it->Previous)
        {
            it->Previous->Next = it->Next;
        }
        if (it == end())
        {
            CurrentElement = it->Previous;
        }
        NumberOfElementsInList--;
    }

private:
    size_t NumberOfElementsInList = 0;
    std::shared_ptr<Element> StartingElement = nullptr;
    std::shared_ptr<Element> CurrentElement = nullptr;
    
    class Iterator 
    {
    public:
        Iterator() = delete;
        Iterator(std::shared_ptr<Element> InElement) : CurrentElement(InElement) {}
        ~Iterator() = default;

        Element& operator*() const 
        {
            return *CurrentElement; 
        }
        std::shared_ptr<Element> operator->() const
        {
            return CurrentElement; 
        }
        Iterator& operator++() 
        {
            CurrentElement = CurrentElement->Next;
            return *this;
        }
        Iterator operator++(int) 
        {
            Iterator tmp = *this; 
            ++(*this); 
            return tmp; 
        }
        friend bool operator==(const Iterator& a, const Iterator& b)
        {
            return a.CurrentElement == b.CurrentElement; 
        }
        friend bool operator!=(const Iterator& a, const Iterator& b) 
        {
            return a.CurrentElement != b.CurrentElement; 
        }
    
        std::shared_ptr<Element> CurrentElement = nullptr;
    };

public:
    Iterator begin()
    {
        return Iterator(StartingElement);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }

    friend std::ostream& operator<<(std::ostream& os, const Element& InElement)
    {
        return os << InElement.Data;
    }
    friend std::ostream& operator<<(std::ostream& os, LinkedList& InLinkedList)
    {
        os << "List contains:\n";
        for (const auto& Element : InLinkedList)
        {
            os << "\t";
            os << "Value = ";
            os << Element.Data;
            os << "\n";
        }
        return os;
    }
};