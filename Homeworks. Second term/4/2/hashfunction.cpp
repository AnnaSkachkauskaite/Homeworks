#include "hashfunction.h"

HashFunction::HashFunction(int val) : value(val)
{
}

int HashFunction::getHash(QString &word, int size)
{
    int result = 0;
    for (int i = 0; i < word.length(); ++i)
        result = (result + value * static_cast<char>(word.toStdString()[i])) % size;
    return result;
}

int HashFunction::getValue()
{
    return this->value;
}
