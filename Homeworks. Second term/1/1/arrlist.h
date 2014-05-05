#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    void addValue(int value);
    void deleteValue(int numb);
    void printList();
    int getSize();
    bool isFind(int numb);

private:
    int size;
    int arr[1000];
};
