#pragma once

class Stack
{
public:
    virtual ~Stack();
    virtual void push(char value) = 0;
    virtual char getTop() = 0;
    virtual char pop() = 0;
    virtual bool isEmpty() = 0;
};
