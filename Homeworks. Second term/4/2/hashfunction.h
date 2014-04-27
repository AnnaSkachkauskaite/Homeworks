#pragma once
#include <QString>
#include <QObject>

///Class for using hash function
class HashFunction
{
public:
    HashFunction(int val);
    ///Method which calculater the value of hash function for given string 
    int getHash(QString &word, int size);
    int getValue();

private:
    int value;
};


