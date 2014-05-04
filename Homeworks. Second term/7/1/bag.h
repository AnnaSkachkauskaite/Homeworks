#pragma once
#include <map>
using namespace std;

///Class for multiset
class Bag
{
public:
    Bag();
    ~Bag();
    ///Add value to multiset
    void incert(int value);
    ///Delete value from multiset
    void remove(int value);
    ///True if multiset contains value
    bool isFind(int value);
    ///Number of elements
    int getSize();

private:
    map<int, int> set;
    int size;
};

