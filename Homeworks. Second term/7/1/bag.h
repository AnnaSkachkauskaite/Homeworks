#pragma once
#include <map>
using namespace std;

class Bag
{
public:
    Bag();
    ~Bag();
    void incert(int value);
    void remove(int value);
    bool isFind(int value);
    int getSize();

private:
    map<int, int> set;
    int size;
};

