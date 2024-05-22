#pragma once
#include <string>

using namespace std;

class Article{
public:
    virtual string GetType() = 0;
    virtual int GetQuantity() = 0;
    virtual int GetPrice() = 0;
    virtual void Print() = 0;
};
