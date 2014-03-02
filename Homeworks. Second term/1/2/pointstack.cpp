#include "pointstack.h"

PointerStack::PointerStack() : top(nullptr), Stack()
{
}

PointerStack::~PointerStack()
{
	while (top != nullptr)
	{
		StackElement *tmp = top->next;
		delete top;
		top = tmp;
	}
}

void PointerStack::push(char value)
{
	StackElement *ptr = new StackElement;
	ptr->symbol = value;                                
	ptr->next = top;
	top = ptr;
}

char PointerStack::getTop()
{
	if (top == nullptr) 
	{
		return '\0'; 
	}
	StackElement *ptr = top;
	return ptr->symbol;
}

char PointerStack::pop()
{
	if (top == nullptr) 
	{
		return '0'; 
	}
	StackElement *ptr = top;
	int a;           
	a = ptr->symbol;
	top = ptr->next;         
	delete(ptr);        
	return a;
}

bool PointerStack::isEmpty()
{
	return top == nullptr;
}

