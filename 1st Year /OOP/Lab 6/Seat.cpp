#include "Seat.h"
#include "Weather.h"
#include <cstring>
#include <iostream>

Seat::Seat()
{
	this -> model = new char[5];
	strcpy (this -> model, "Seat");
	this -> FuelConsumption = 7;
	this -> FuelCapacity = 60;
	this -> AverageSpeed = 90;
}

int Seat::GetFuelCapacity()
{
	return this -> FuelCapacity;
}

int Seat::GetFuelConsumption()
{
	return this -> FuelConsumption;
}

int Seat::GetAverageSpeed(Weather weather)
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

const char* Seat::GetName()
{
	return this -> model;
}

//Damian Cozma - April 2024
