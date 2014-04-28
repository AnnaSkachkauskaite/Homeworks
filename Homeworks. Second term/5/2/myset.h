#pragma once
#include <iostream>
#include <QList>

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
    MySet<T> intersection(MySet<T> secSet);
    MySet<T> unification(MySet<T> secSet);
    void print();
private:
    QList<T> list;
};

template <typename T>
MySet<T>::MySet()
{
}

template <typename T>
MySet<T>::~MySet()
{
    list.clear();
}


template <typename T>
void MySet<T>::incert(T value)
{
    if (!list.contains(value))
        list.push_back(value);
}

template <typename T>
void MySet<T>::del(T value)
{
    if (!(this->isFind(value)))
        return;
    list.removeOne(value);

}

template <typename T>
bool MySet<T>::isFind(T value)
{
    return list.contains(value);
}

template <typename T>
bool MySet<T>::isEmpty()
{
    return list.size() == 0;
}

template <typename T>
int MySet<T>::getSize()
{
    return list.size();
}

template <typename T>
MySet<T> MySet<T>::intersection( MySet<T> secSet)
{
    MySet<T> result;
    for (int i = 0; i < list.size(); ++i)
        if (secSet.isFind(list[i]))
            result.incert(list[i]);
    return result;
}

template <typename T>
MySet<T> MySet<T>::unification( MySet<T> secSet)
{
    MySet<T> result;
    for (int i = 0; i < list.size(); ++i)
        result.incert(list[i]);
    for (int i = 0; i < secSet.list.size(); ++i)
        if(!result.isFind(secSet.list[i]))
            result.incert(secSet.list[i]);
    return result;
}

template <typename T>
void MySet<T>::print()
{
    for (int i = 0; i < list.size(); ++i)
        std::cout << list[i] << " ";
    std::cout << "\n";
}

