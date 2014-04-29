#pragma once

class List
{
public:
    virtual ~List() = 0;
    virtual void addValue (int numb) = 0;
    virtual void deleteValue (int numb) = 0;
    virtual void printList() = 0;

};

