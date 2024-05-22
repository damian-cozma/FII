#pragma once
#include "Animal.h"

class Eagle : public Animal{
    string GetName()
    {
        return (string)"Eagle";
    }

    bool IsAFish()
    {
        return false;
    }

    bool IsABird()
    {
        return true;
    }

    bool IsAMammal()
    {
        return false;
    }
};
