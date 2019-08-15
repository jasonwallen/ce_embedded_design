#include "Car.h"
#include <iostream>

Car::Car(std::string license, int year)
{
	this->license = license;
	this->year = year;
}

Car::~Car()
{
	
}

std::string Car::LicensePlateNumber()
{
	return license;	
}

int Car::Age()
{
	return (2018-year);
}
