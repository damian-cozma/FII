#include <iostream>
#include "Shop.h"
#include "Book.h"
#include "Apple.h"
#include "VideoGame.h"

int main()
{
    Shop s;
    s.Add(new Book(100, 3, "Dune", "Frank Herbert")).Add(new Apple(20, 100, "Romania"));
    s.Add(new VideoGame(10, 2, "Nintendo", "Super Mario"));
    s.Add(new Apple(12, 15, "Germany"));
    std::cout << "Total price   : " << s.GetTotalPrice() << std::endl;
    std::cout << "Apple quantity: " << s.GetQuantity("Apple") << std::endl;
    std::cout << "Items" << std::endl;
    s.List();
    return 0;
}
