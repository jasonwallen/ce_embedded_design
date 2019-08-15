#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
	float radius;

public:
	
	Circle(std::string name, float radius);

	void Print();

	float getArea();
};

#endif
