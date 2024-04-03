#pragma once
#include "Car.h"
class RangeRover : public Car
{
private:
	char* model;
	int FuelConsumption;
	int FuelCapacity;
	int AverageSpeed;

public:
	RangeRover();
	int GetFuelCapacity();
	int GetFuelConsumption();
	int GetAverageSpeed(Weather);
	const char* GetName();
};

//Damian Cozma - April 2024
