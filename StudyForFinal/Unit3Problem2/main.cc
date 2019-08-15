#include <iostream>
#include <string>

class Car
{
	std::string license;
	int year;

public:

	Car(std::string license, int year){
		
		this->license = license;
		this->year = year;
	}

	~Car(){}

	PrintInfo()
	{
		std::cout << "Car with license plate " << license << " is " << (2018-year) << " years old.\n";
	}

};

int main()
{
	std::cout << "Number of cars: ";
	int cars;
	std::cin >> cars;

	

	Car *car = new car[cars];

	
}
