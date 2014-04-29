#include "uniquelist.h"

bool UniqueList::isFind(int value)
{
    ListElement *tmp = first;
    while(tmp != nullptr)
    {
        if (tmp->value == value)
            return true;
        tmp = tmp->next;
    }
    return false;
}

void UniqueList::addToUniqueList(int value) throw (DuplicateExeption)
{
    if (isFind(value))
        throw DuplicateExeption("This element is exist in tge list");
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

void UniqueList::delFromUniqueList(int value) throw (NonexistentElemenyExeption)
{
    if (!isFind(value))
        throw NonexistentElemenyExeption("Can't delete, element dosen't find");
    ListElement *tmp = this->first;
    while ((tmp->next->value != value) && (tmp->next->next != nullptr))
    {
        tmp = tmp->next;
    }
    ListElement *delValue = tmp->next;
    tmp->next = tmp->next->next;
    delete(delValue);
}
