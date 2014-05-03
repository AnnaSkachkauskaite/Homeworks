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
    ///True if hash table contains given word
    bool isFind(QString &word);
    ///Insert word to hashtable
    void add(QString &word);
    ///Delete word from hashtable
    void deleteWord(QString &word);
    ///Returns hashtable size
    int tableSize();
    double loadFactor();
    int numOfConf();
    int maxConf();
    ///Cange hash function in the table
    void changeFunction (HashFunction *newFunction);
    void printTable();
    int hashValue();
    
private:
    HashFunction *hash;
    QStringList *table;
    int size;
};


