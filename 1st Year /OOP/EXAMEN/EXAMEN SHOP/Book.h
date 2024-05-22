#pragma once
#include "Article.h"
#include <string>

using namespace std;

class Book : public Article{
private:
    int qt, price;
    string titlu, autor;
public:
    Book(int price, int qt, string titlu, string autor);
    string GetType();
    int GetQuantity();
    int GetPrice();
    void Print();
};
