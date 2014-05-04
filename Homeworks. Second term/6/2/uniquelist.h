#pragma once
#include "pointlist.h"
#include "nonexistentelemenyexeption.h"
#include "duplicateexeption.h"

class UniqueList : public PointerList
{
public:
    ~UniqueList() {}
    ///Add element to the list(if list doesn't contains it)
    void addToUniqueList(int value) throw (DuplicateExeption);
    ///Delete element from the list(if list contains it)
    void delFromUniqueList(int value) throw (NonexistentElemenyExeption);
    bool isFind(int value);
};


