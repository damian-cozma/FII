#pragma once
#include "Weather.h"

class Car
{
public:
	virtual int GetFuelCapacity() = 0;
	virtual int GetFuelConsumption() = 0;
	virtual int GetAverageSpeed(Weather) = 0;
	virtual const char* GetName() = 0;
};

//Damian Cozma - April 2024
