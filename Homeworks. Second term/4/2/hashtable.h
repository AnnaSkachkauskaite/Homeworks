#pragma once
#include "hashfunction.h"
#include <QStringList>

///Class for using hash table
class HashTable
{
public:
    HashTable();
    HashTable(int newSize);
    HashTable(int newSize, HashFunction *hashfunc);
   ~HashTable();
    bool isFind(QString &word);
    void add(QString &word);
    void deleteWord(QString &word);
    int tableSize();
    double loadFactor();
    int numOfConf();
    int maxConf();
    void changeFunction (HashFunction *newFunction);
    void printTable();
    int hashValue();
    
private:
    HashFunction *hash;
    QStringList *table;
    int size;
};


