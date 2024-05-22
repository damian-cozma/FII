#pragma once
#include "Article.h"
#include <string>

using namespace std;

class VideoGame : public Article{
private:
    int qt, price;
    string platform, name;
public:
    VideoGame(int price, int qt, string platform, string name);
    string GetType();
    int GetQuantity();
    int GetPrice();
    void Print();
};
