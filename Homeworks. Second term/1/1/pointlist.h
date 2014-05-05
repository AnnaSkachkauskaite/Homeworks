#pragma once
#include "list.h"

class PoinerList : public List
{
public:
    PoinerList();
    ~PoinerList();
    void addValue(int value);
    void deleteValue(int numb);
    void printList();
    void deleteList();
    int getSize();
    bool isFind(int numb);

private:
    struct ListElement
    {
        int value;
        ListElement *next;
    };

    ListElement *first;
    int size;
};
