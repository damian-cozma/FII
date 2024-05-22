#pragma once
#include "Animal.h"

class Cow : public Animal{
    string GetName()
    {
        return (string)"Cow";
    }

    bool IsAFish()
    {
        return false;
    }

    bool IsABird()
    {
        return false;
    }

    bool IsAMammal()
    {
        return true;
    }
};
