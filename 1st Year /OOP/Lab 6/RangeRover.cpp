#include "RangeRover.h"
#include "Weather.h"
#include <iostream>

RangeRover::RangeRover()
{
	this -> model = new char[11];
	strcpy (this -> model, "RangeRover");
	this -> FuelConsumption = 10;
	this -> FuelCapacity = 100;
	this -> AverageSpeed = 100;
}

int RangeRover::GetFuelCapacity()
{
	return this -> FuelCapacity;
}

int RangeRover::GetFuelConsumption()
{
	return this -> FuelConsumption;
}

int RangeRover::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return this -> AverageSpeed - 10;
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

const char* RangeRover::GetName()
{
	return this -> model;
}

//Damian Cozma - April 2024
