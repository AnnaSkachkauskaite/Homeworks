#include "arrstack.h"

ArrayStack::ArrayStack() : size(-1), Stack()
{
}

void ArrayStack::push(char value)
{
    ++size;
    stack[size] = value;
}

char ArrayStack::pop()
{
    --size;
    return stack[size + 1];
}

char ArrayStack::getTop()
{
    return stack[size];
}

bool ArrayStack::isEmpty()
{
    return size == -1;
}

