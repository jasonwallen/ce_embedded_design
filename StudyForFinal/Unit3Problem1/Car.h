#ifndef CAR_H
#define CAR_H

#include <string>

class Car{

	std::string license;
	int year;

public:
	
	//Constructor
	Car(std::string license, int year);
	
	//Destructor
	~Car();

	//Returns the licence plate number
	std::string LicensePlateNumber();

	//Returns car age based on when it was sold
	int Age();

	

};


#endif
