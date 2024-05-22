#include "Shop.h"
#include "Article.h"
#include <iostream>

using namespace std;

int Shop::GetTotalPrice() {
    int price = 0;
    for (auto i: items)
    {
        price = price + i->GetPrice();
    }

    return price;
}

int Shop::GetQuantity(string nume) {
    int qt = 0;
    for (auto i: items)
    {
        if (i->GetType() == "Apple")
            qt  = qt + i->GetQuantity();
    }

    return qt;
}

void Shop::List()
{
    for (auto i: items)
    {
        i->Print();
        cout << endl;
    }
}




