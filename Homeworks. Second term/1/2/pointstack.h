#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(char value);
    char getTop();
    char pop();
    bool isEmpty();

private:
    struct StackElement
    {
        char symbol;
        StackElement *next;
    };
    StackElement *top;
};

