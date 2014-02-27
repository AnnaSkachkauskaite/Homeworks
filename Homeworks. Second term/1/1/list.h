#pragma once
//#include "element.h"

class List
{
public:
	List();
	~List();
	virtual void addValue (int numb) = 0;
	virtual void deleteValue (int numb) = 0;
	virtual void printList() = 0;

};
