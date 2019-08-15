#include "Rectangle.h"
	

Rectangle::Rectangle(std::string name)
{
	this->name = name;
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle destroyed\n";	
}

void Rectangle::setDimensions(float width, float height)
{
	//'this->width' represents the class field named 'width'
	//and 'width' represents the function argument.
	//
	//'this' is a pointer to the current instance.
	this->width = width;
	this->height = height;
}

float Rectangle::getArea()
{
	return width * height;
}
