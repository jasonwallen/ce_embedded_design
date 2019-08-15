#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

//Class 'Rectangle' is a child of class 'Shape'
class Rectangle : public Shape
{
	float width;
	float height;

public:
	
	Rectangle(std::string name, float width, float height);
};

#endif
