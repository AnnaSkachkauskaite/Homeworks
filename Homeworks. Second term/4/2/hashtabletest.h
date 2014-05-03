#pragma once
#include "hashtable.h"

#include <QObject>
#include <QtTest/QtTest>

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0);

private slots:

    void init()
    {
        table = new HashTable(100);
    }

    void cleanup()
    {
        delete table;
    }

    void addWordTest()
    {
        QString word = QString("asd");
        table->add(word);
        QVERIFY(table->isFind(word));
    }

    void deleteWordTest()
    {
        QString word = QString("dfg");
        table->add(word);
        table->deleteWord(word);
        QVERIFY(!table->isFind(word));
    }

    void tableSizeTest()
    {
        QVERIFY(table->tableSize() == 100);
    }

    void changeHashTest()
    {
        QString word = QString("qwe");
        table->add(word);
        table->changeFunction(new HashFunction(123));
        QVERIFY(table->isFind(word));
    }

private:
    HashTable *table;

};

