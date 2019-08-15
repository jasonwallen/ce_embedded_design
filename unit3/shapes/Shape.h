#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
	std::string name;

public:

	Shape(std::string name);
	
	// Print the shape
	virtual void Print();

	// Returns the area of a shape. The '= 0' suffix indicates that this is
	// a pure virtual function. This makes 'Shape' an abstract class,
	// which means:
	//
	// 1) Class 'Shape' cannot be instantiated directly.
	//
	// 2) Every child class must implement function 'getArea()'.
	//
	virtual float getArea() = 0; // This '0' is not a '0' and this '=' is not a '='
};

#endif
