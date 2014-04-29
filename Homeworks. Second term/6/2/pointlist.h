#pragma once
#include "list.h"

class PointerList : public List
{
public:
    PointerList();
    ~PointerList();
    void addValue(int value);
    void deleteValue(int numb);
    void printList();
    int length();
    void deleteList();

protected:
    struct ListElement
    {
        int value;
        ListElement *next;
    };

    ListElement *first;
};
