#include <iostream>
#include "pointlist.h"

PoinerList::PoinerList() : size(0)
{
    this->first = new ListElement;
    this->first->next = nullptr;

}

PoinerList::~PoinerList()
{
    deleteList();
}

void PoinerList::addValue(int value)
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
    ++size;
}

void PoinerList::deleteValue(int numb)
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
        --size;
    }
}

bool PoinerList::isFind(int numb)
{
    ListElement *tmp = this->first;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
        if (tmp->value == numb)
            return true;
    }
    return false;
}


void PoinerList::printList()
{
    ListElement *tmp = this->first->next;
    while (tmp != nullptr)
    {
        std::cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    std::cout<<"\n";
}

void PoinerList::deleteList()
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

int PoinerList::getSize()
{
    return size;
}
