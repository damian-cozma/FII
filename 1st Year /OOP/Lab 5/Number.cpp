//UNFINISHED

#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>

using namespace std;

//Number constructor

Number::Number(const char* value, int base)
{
	this -> value = new char[strlen(value) + 1];
	strcpy(this -> value, value);
	this -> base = base;
	this->decimal = strtol(value, nullptr, base);
}

Number::Number(const int nr)
{
	this -> base = 10;
	this -> decimal = nr;
	this -> value = new char[10];
	_itoa(nr, this -> value, 10);
}

Number::~Number()
{
	delete [] this -> value;
}

//Operators

Number operator+(const Number& A, const Number& B)
{
	int val = A.decimal + B.decimal;
	int base = max(A.base, B.base);

	char* value = new char[10];
	_itoa(val, value, base);
	return Number(value, base);
}

Number operator-(const Number& A, const Number& B)
{
	int val = A.decimal - B.decimal;
	int base = max(A.base, B.base);

	char* value = new char[10];
	_itoa(val, value, base);
	return Number(value, base);
}

Number operator+=(const Number& A, const Number& B)
{
	int val = A.decimal + B.decimal;
	int base = max(A.base, B.base);

	char* value = new char[10];
	_itoa(val, value, base);
	return Number(value, base);
}

bool Number::operator>(const Number& A)
{
	return this->decimal > A.decimal;
}

void Number::operator=(const Number& A)
{
	this->decimal = A.decimal;
	this->base = A.base;
	this->value = new char[strlen(A.value) + 1];
	strcpy(this->value, A.value);
}

void Number::operator=(const int nr)
{
	this->decimal = nr;
	this->base = 10;
	this->value = new char[10];
	_itoa(nr, this->value, 10);
}

int Number::operator[](int index)
{
	return this->value[index];
}

//Get

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int Number::GetBase()
{
	return base;
}

//Other functions

void Number::Print()
{
	cout << this -> value << endl;
}

void Number::SwitchBase(int newBase)
{
	char* value = new char[10];
	_itoa(this->decimal, value, newBase);
	this->base = newBase;
	this->value = value;
}

//Damian Cozma - March 2024
