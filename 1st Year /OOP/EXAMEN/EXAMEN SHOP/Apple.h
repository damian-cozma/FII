#pragma once
#include "Article.h"
#include <string>

using namespace std;

class Apple : public Article{
private:
    int qt, price;
    string from;
public:
    Apple(int price, int qt, string from);
    string GetType();
    int GetQuantity();
    int GetPrice();
    void Print();
};
