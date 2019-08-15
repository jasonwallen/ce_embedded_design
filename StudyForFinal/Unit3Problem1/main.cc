#include "Car.h"
#include <iostream>

int main()
{
	std::string licence;
	std::cout << "Please input a license plate number: ";
	std::cin >> licence;

	int year;
	std::cout << "Please input the year the car was sold: ";
	std::cin >> year;

	Car car(licence, year);

	std::cout << "The liscence plate number is " << car.LicensePlateNumber() << " and the car is " << car.Age() << " years old.\n";

	return 0;
}

