#include "Fiat.h"
#include "Weather.h"
#include <iostream>
#include <cstring>

Fiat::Fiat()
{
	this -> model = new char[5];
	strcpy (this -> model, "Fiat");
	this -> FuelConsumption = 10;
	this -> FuelCapacity = 40;
	this -> AverageSpeed = 30;
}

int Fiat::GetFuelCapacity()
{
	return this -> FuelCapacity;
}

int Fiat::GetFuelConsumption()
{
	return this -> FuelConsumption;
}

int Fiat::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
	{
		return this -> AverageSpeed - 20;
	}
	else if (weather == Weather::Sunny)
	{
		return this -> AverageSpeed;
	}
	else
	{
		return this -> AverageSpeed - 25;
	}
}

const char* Fiat::GetName()
{
	return this -> model;
}

//Damian Cozma - April 2024
