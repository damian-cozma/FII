#include "BMW.h"
#include "Weather.h"
#include <iostream>
#include <cstring>

BMW::BMW()
{
	this -> model = new char[4];
	strcpy (this -> model, "BMW");
	this -> FuelConsumption = 6;
	this -> FuelCapacity = 55;
	this -> AverageSpeed = 85;
}

int BMW::GetFuelCapacity()
{
	return this -> FuelCapacity;
}

int BMW::GetFuelConsumption()
{
	return this -> FuelConsumption;
}

int BMW::GetAverageSpeed(Weather weather)
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

const char* BMW::GetName()
{
	return this -> model;
}

//Damian Cozma - April 2024
