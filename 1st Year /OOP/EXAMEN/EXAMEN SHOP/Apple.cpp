#include "Apple.h"
#include <iostream>

Apple::Apple(int price, int qt, string from) {
    this -> qt = qt;
    this -> price = price;
    this -> from = from;
}

string Apple::GetType() {
    return (string)"Apple";
}

int Apple::GetQuantity() {
    return this -> qt;
}

int Apple::GetPrice() {
    return this -> price * qt;
}

void Apple::Print() {
    std::cout << GetType() << " (" << "From="  << this->from << ") Price=" << this->price << " Quantity=" << this->qt;
}








