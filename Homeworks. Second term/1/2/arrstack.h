#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    void push(char value);
    char getTop();
    char pop();
    bool isEmpty();

private:
    char stack[1000];
    int size;
};
