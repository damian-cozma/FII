#include "VideoGame.h"
#include <iostream>

VideoGame::VideoGame(int price, int qt, string platform, string name) {
    this -> qt = qt;
    this -> price = price;
    this -> platform = platform;
    this -> name = name;
}

string VideoGame::GetType() {
    return (string)"VideoGame";
}

int VideoGame::GetQuantity() {
    return this -> qt;
}

int VideoGame::GetPrice() {
    return this -> price * qt;
}

void VideoGame::Print() {
    std::cout << GetType() << " (" << "Platform=" << this->platform << ", Name=" << this->name << ") Price=" << this->price << " Quantity=" << this->qt;
}








