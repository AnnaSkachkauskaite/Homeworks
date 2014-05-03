#include <QTextStream>
#include <iostream>
#include "hashtable.h"
#include "hashtabletest.h"

using namespace std;

enum UserCommand
{
    close,
    print,
    add,
    del,
    contains,
    statistic,
    change
};

void changeHashFunc(HashTable *myTable)
{
    cout <<"Choose new value for hash function\n1 - 239\n2 - 751\n3 - 1033\n";
    int funcNumb = 0;
    bool isCorrect = false;
    while (!isCorrect)
    {
        cin >> funcNumb;
        if (funcNumb == 1)
        {
            myTable->changeFunction(new HashFunction(239));
            isCorrect = true;
        }
        else  if (funcNumb == 2)
        {
            myTable->changeFunction(new HashFunction(751));
            isCorrect = true;
        }
        else  if (funcNumb == 3)
        {
            myTable->changeFunction(new HashFunction(1033));
            isCorrect = true;
        }
        else
            cout << "Incorrect number! Try again\n";
    }
}

int main()
{
    HashTableTest test;
    QTest::qExec(&test);
    HashTable *myTable = new HashTable(1000, new HashFunction(239));
    cout <<"Hash function value is "<< myTable->hashValue() << "\n\nCommand list\n1 - print - prints HashTable \n2 - add word to hashtable \n3 - delete word from hashtable \n4 - checks if hastable contaitns word \n5 - shows statistics for table \n6 - change hash function \n";
    cout << "0 - exit programm \n";
    UserCommand command;
    QString word;
    char *str = new char[100];
    int tmp;
    cin >> tmp;
    command = static_cast<UserCommand>(tmp);
    while (command != close)
    {
        switch (command)
        {
        case print:
            myTable->printTable();
            break;
        case add:
            cout << "Enter word  ";
            cin >> str;
            word = QString(str);
            myTable->add(word);
            break;
        case del:
            cout << "Enter word  ";
            cin >> str;
            word = QString(str);
            myTable->deleteWord(word);
            break;
        case contains:
            cout << "Enter word  ";
            cin >> str;
            word = QString(str);
            myTable->isFind(word);
            break;
        case statistic:
            cout << "Load factor " << myTable->loadFactor() << "\nNumber of conflicts " << myTable->numOfConf() << "\nMax conflict " << myTable->maxConf() << "\n";
            break;
        case change:
            changeHashFunc(myTable);
            break;
        default:
            cout << "Wrong number!\n";
            break;
        }
        cin >> tmp;
        command = static_cast<UserCommand>(tmp);
    }
    delete []str;
    delete myTable;
}
