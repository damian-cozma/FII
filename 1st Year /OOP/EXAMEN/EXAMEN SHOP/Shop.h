#pragma once
#include "Article.h"
#include "Shop.h"
#include <vector>

using namespace std;

class Shop {
private:
    vector<Article*> items;
public:
    Shop& Add(Article *nume)
    {
        items.push_back(nume);
        return *this;
    }
    int GetTotalPrice();
    int GetQuantity(string nume);
    void List();
};
