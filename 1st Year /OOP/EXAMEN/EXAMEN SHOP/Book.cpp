#include "Book.h"
#include <iostream>

Book::Book(int price, int qt, string titlu, string autor) {
    this -> qt = qt;
    this -> price = price;
    this -> titlu = titlu;
    this -> autor = autor;
}

string Book::GetType() {
    return (string)"Book";
}

int Book::GetQuantity() {
    return this -> qt;
}

int Book::GetPrice() {
    return this -> price * qt;
}

void Book::Print() {
    std::cout << GetType() << " (" << "Title=" << this->titlu << ", Author=" << this->autor << ") Price=" << this->price << " Quantity=" << this->qt;
}








