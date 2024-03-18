#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <iostream>
#include <cstdarg>
#include <cstring>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list args;
	va_start(args, count);

	int s = 0;

	while (count != 0)
	{
		s = s + va_arg(args, int);
		count--;
	}

	va_end(args);
	return s;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}

	char* s = new char[strlen(a) + strlen(b) + 1];
	strcpy(s, a);
	strcat(s, b);
	return s;
}

//Damian Cozma - March 2024
