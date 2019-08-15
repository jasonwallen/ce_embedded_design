#include "Shape.h"

Shape::Shape(std::string name)
{
	this->name = name;
}

void Shape::Print()
{
	std::cout << "Shape " << name << '\n';
}
