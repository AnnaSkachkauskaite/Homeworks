#include <iostream>
#include "pointlist.h"

PointerList::PointerList()
{
    this->first = new ListElement;
    this->first->next = nullptr;

}

PointerList::~PointerList()
{
    deleteList();
}

void PointerList::addValue(int value)
{
    ListElement *tmp = this->first;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    ListElement *addValue = new ListElement;
    addValue->value = value;
    addValue->next = tmp->next;
    tmp->next = addValue;
}

void PointerList::deleteValue(int numb)
{
    ListElement *tmp = this->first;
    bool delEl = false;
    while ((tmp->next->value != numb) && (tmp->next->next != nullptr))
    {
        tmp = tmp->next;
        if (tmp->next->value == numb)
        {
            delEl = true;
        }
    }
    if (!delEl)
    {
        printf("Element not found\n");
    }
    else
    {
        ListElement *delValue = tmp->next;
        tmp->next = tmp->next->next;
        delete(delValue);
    }
}


void PointerList::printList()
{
    ListElement *tmp = this->first->next;
    while (tmp != nullptr)
    {
        std::cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    std::cout<<"\n";
}

int PointerList::length()
{
    ListElement *tmp = first;
    int result = 0;
    while(tmp != nullptr)
    {
        result++;
        tmp = tmp->next;
    }
    return result;
}

void PointerList::deleteList()
{
    ListElement *tmp = this->first;
    ListElement *delValue = tmp;
    while (tmp)
    {
        delValue = tmp;
        tmp = tmp->next;
        delete(delValue);
    }
}

