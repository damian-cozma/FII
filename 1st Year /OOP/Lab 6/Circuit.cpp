#include "Circuit.h"
#include "Car.h"
#include <iostream>
using namespace std;

Circuit::Circuit()
{
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	for (int i = 0; i < 10; i++)
	{
		if (cars[i] == nullptr)
		{
			cars[i] = car;
			break;
		}
	}
}

void Circuit::Race()
{
	for (int i = 0; i < 10; i++)
	{
		if (cars[i] != nullptr)
		{
			cout << cars[i]->GetName() << endl;
			cout << "Capacitatea de combustibil: " << cars[i]->GetFuelCapacity() << endl;
			cout << "Consumul de combustibil: " << cars[i]->GetFuelConsumption() << endl;
			cout << "Viteza medie: " << cars[i]->GetAverageSpeed(weather) << endl;
			cout << "---------------------------------------------------\n";
		}
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		Car* aux = cars[i];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (cars[i] != nullptr && cars[j] != nullptr)
			{
				if (cars[i]->GetAverageSpeed(weather) > cars[j]->GetAverageSpeed(weather))
				{
					Car* aux = cars[i];
					cars[i] = cars[j];
					cars[j] = aux;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (cars[i] != nullptr)
		{
			int timp = length / cars[i]->GetAverageSpeed(weather);
			int combustibil = cars[i]->GetFuelCapacity() - cars[i]->GetFuelConsumption() * timp;

			if (combustibil < 0)
			{
				cars[i] = nullptr;
			}
		}
	}
	
}

void Circuit::ShowFinalRanks()
{
	int loc = 0;
	for (int i = 0; i < 10; i++)
	{
		if (cars[i] != nullptr)
		{
			cout << "Locul " << ++loc << ": ";
			cout << cars[i]->GetName() << " " << (float)length / cars[i]->GetAverageSpeed(weather);
			cout << endl;
		}
	}
	cout << endl;
}

//NETERMINAT
void Circuit::ShowWhoDidNotFinish()
{
	cout << "Fara combustibil: " << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cars[i] != nullptr)
		{
			//unfinished
		}
	}
}

//Damian Cozma - April 2024
