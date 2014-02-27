#include <iostream>
#include "arrlist.h"

ArrayList::ArrayList() : size(0)
{
}

void ArrayList::addValue(int value)
{
	arr[size] = value;
	++size;
}

void ArrayList::deleteValue(int value)
{
	int i = 0;
	bool isFind = false;
	while ((i < size) && (arr[i] != value))
		++i;
	if (arr[i] == value)
			isFind = true;
	if (!isFind)
	{
		std::cout<<"Element not found\n";
		return;
	}
	for (int j = i; j < size - 1; ++j)
		arr[j] = arr[j + 1];
	--size;
}

void ArrayList::printList()
{
	for (int i = 0; i < size; ++i)
		std::cout<<arr[i]<<" ";
	std::cout<<"\n";
}