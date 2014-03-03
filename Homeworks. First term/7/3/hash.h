#pragma once
#include <stdio.h>
#include "stringUnit.h"
#include "list.h"


struct HashElem 
{
	List *list;
};

void createHashArr (HashElem *hashArr[hashMax]);

void makeHashArr (HashElem *hashArr[hashMax], FILE *file, int length[hashMax]);