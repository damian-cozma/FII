#pragma once
#include "Car.h"
class BMW : public Car
{
private:
	char* model;
	int FuelConsumption;
	int FuelCapacity;
	int AverageSpeed;

public:
	BMW();
	int GetFuelCapacity();
	int GetFuelConsumption();
	int GetAverageSpeed(Weather);
	const char* GetName();
};

//Damian Cozma - April 2024
