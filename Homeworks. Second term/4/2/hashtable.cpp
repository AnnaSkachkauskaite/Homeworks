#include "hashtable.h"
#include <iostream>

HashTable::HashTable() : hash(new HashFunction(1000)), table(new QStringList[1]), size(1)
{
}

HashTable::HashTable(int newSize) : hash(new HashFunction(1000)), table(new QStringList[newSize]), size(newSize)
{
}

HashTable::HashTable(int newSize, HashFunction *hashfunc) : hash(hashfunc), table(new QStringList[newSize]), size(newSize)
{
}

HashTable::~HashTable()
{
    delete hash;
    delete []table;
}

bool HashTable::isFind(QString &word)
{
    return table[hash->getHash(word, size)].contains(word);
}

void HashTable::add(QString &word)
{
    if (this->isFind(word))
        return;
    table[hash->getHash(word, size)].append(word);
}

void HashTable::deleteWord(QString &word)
{
    if (!(this->isFind(word)))
    {
        std::cout <<"This word isn't found" << std::endl;
        return;
    }
    table[hash->getHash(word, size)].removeOne(word);
}

int HashTable::tableSize()
{
    return size;
}

double HashTable::loadFactor()
{
    int tmp = 0;
    for (int i = 0; i < this->tableSize(); ++i)
        if (table[i].size() > 0)
            ++tmp;

    return (double) tmp / this->tableSize();
}

int HashTable::numOfConf()
{
    int tmp = 0;
    for (int i = 0; i < this->tableSize(); ++i)
        if (table[i].size() > 1)
            ++tmp;

    return tmp;
}

int HashTable::maxConf()
{
    int max = 0;
    for (int i = 0; i < this->tableSize(); ++i)
        if (table[i].size() > max)
            max = table[i].size();
    return max;
}

void HashTable::changeFunction(HashFunction *newFunction)
{
    delete hash;
    hash = newFunction;
    QStringList *newTable = new QStringList[this->tableSize()];
    for (int i = 0; i < this->tableSize(); ++i)
    {
        int tmp = table[i].size();
        for (int j = 0; j < tmp; ++j)
        {
            newTable[hash->getHash(table[i].first(), size)].append(table[i].first());
            table[i].removeFirst();
        }
    }
    delete []table;
    table = newTable;

}

void HashTable::printTable()
/*{
    for (int i = 0; i < this->tableSize(); ++i)
        if (!table[i].isEmpty())
        {
            QString tmp = table[i];
            std::cout << tmp.toStdString() << std::endl;
        }
}*/
{
    for(int i = 0; i < size; i++)
    {
        if(!table[i].isEmpty())
        {
            for(QString &str : table[i])
            {
                std::cout << "( " << str.toStdString() << " , " << i << " ) ";
            }
            std::cout << std::endl;
        }
    }
}

int HashTable::hashValue()
{
    return this->hash->getValue();
}
