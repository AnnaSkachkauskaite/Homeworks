#pragma once
#include "list.h"

class ArrayList : public List
{
public:
	ArrayList();
	~ArrayList();
	void addValue(int value);
	void deleteValue(int numb);
	void printList();

private:
	int size;
	int arr[1000];
};

