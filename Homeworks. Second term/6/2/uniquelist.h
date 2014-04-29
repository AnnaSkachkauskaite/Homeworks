#pragma once
#include "pointlist.h"
#include "nonexistentelemenyexeption.h"
#include "duplicateexeption.h"

class UniqueList : public PointerList
{
public:
    ~UniqueList() {}
    void addToUniqueList(int value) throw (DuplicateExeption);
    void delFromUniqueList(int value) throw (NonexistentElemenyExeption);
    bool isFind(int value);
};


