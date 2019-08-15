#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
	float width;
	float height;
	std::string name;

public:
	
	//Constructor
	Rectangle(std::string name);

	//Destructor
	~Rectangle();

	//Set the rectangle dimensions
	void setDimensions(float width, float height);

	//Return the area of the rectangle
	float getArea();
};

#endif

