#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit{	
private:
	int length;
	Weather weather;
	Car* cars[10];
	int* podium;

public:
	Circuit();
	void SetLength(int length);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

//Damian Cozma - April 2024
