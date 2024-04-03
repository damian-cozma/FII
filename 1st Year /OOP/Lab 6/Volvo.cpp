#include "Volvo.h"
#include "Weather.h"
#include <iostream>
#include <cstring>

Volvo::Volvo()
{
	this -> model = new char[6];
	strcpy (this -> model, "Volvo");
	this -> FuelConsumption = 8;
	this -> FuelCapacity = 65;
	this -> AverageSpeed = 95;
}

int Volvo::GetFuelCapacity()
{
	return this -> FuelCapacity;
}

int Volvo::GetFuelConsumption()
{
	return this -> FuelConsumption;
}

int Volvo::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return this -> AverageSpeed - 15;
	}
	else if (weather == Weather::Sunny)
	{
		return this -> AverageSpeed;
	}
	else
	{
		return this -> AverageSpeed - 20;
	}
}

const char* Volvo::GetName()
{
	return this -> model;
}

//Damian Cozma - April 2024
