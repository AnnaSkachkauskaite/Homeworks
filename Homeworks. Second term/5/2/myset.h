#pragma once
#include <iostream>

template <typename T>
///Class for set
class MySet
{
public:
    MySet();
    ~MySet();
    ///Insert value into the set
    void incert(T value);
    ///Delete value from the set
    void del(T value);
    ///Is the set contains given element
    bool isFind(T value);
    ///Returns size of the set
    int getSize();
    bool isEmpty();
    MySet<T> intersection(MySet<T> *secSet);
    MySet<T> unification( MySet<T> *secSet);
    void print();
private:
    struct SetElement
        {
            T value;
            SetElement *next;
        };
        SetElement *first;
        int size;
};

template <typename T>
MySet<T>::MySet()
{
    this->first = new SetElement();
    this->first->next = nullptr;
    this->size = 0;
}

template <typename T>
MySet<T>::~MySet()
{
    SetElement *tmp = this->first;
    SetElement *delValue = tmp;
    while (tmp)
    {
        delValue = tmp;
        tmp = tmp->next;
        delete(delValue);
     }
}

template <typename T>
void MySet<T>::incert(T value)
{
    SetElement *tmp = this->first;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    SetElement *addValue = new SetElement;
    addValue->value = value;
    addValue->next = tmp->next;
    tmp->next = addValue;
    ++size;
}

template <typename T>
void MySet<T>::del(T value)
{
    if (!(this->isFind(value)))
        return;
    SetElement *tmp = this->first->next;
    while (tmp->value != value)
        tmp = tmp->next;
    SetElement *delValue = tmp;
    tmp = tmp->next;
    delete(delValue);
    --size;

}

template <typename T>
bool MySet<T>::isFind(T value)
{
    bool contains = false;
    if (this->isEmpty())
        return false;
    SetElement *tmp = this->first;
    while ((!contains) || (tmp->next != nullptr))
    {
        if (tmp->value == value)
            contains = true;
        if (contains)
            return true;
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
bool MySet<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int MySet<T>::getSize()
{
    return this->size;
}

template <typename T>
MySet<T> MySet<T>::intersection( MySet<T> *secSet)
{
    SetElement *tmp = this->first;
    MySet *result = new MySet();
    while(tmp->next != nullptr)
    {
        if(secSet->isFind(tmp->value))
            result->incert(tmp->value);
        tmp = tmp->next;

    }
    return result;
}

template <typename T>
MySet<T> MySet<T>::unification( MySet<T> *secSet)
{
    SetElement *tmp = this->first;
    MySet *result = new MySet();
    while(tmp->next != nullptr)
    {
        result->incert(tmp->value);
        tmp = tmp->next;

    }
    delete tmp;
    tmp = secSet->first;
    while(tmp->next != nullptr)
    {
        if(!(result->isFind(tmp->value)))
            result->incert(tmp->value);
        tmp = tmp->next;

    }
    return result;
}

template <typename T>
void MySet<T>::print()
{
    SetElement *tmp = this->first;
    while(tmp->next != nullptr)
    {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << "\n";
}

