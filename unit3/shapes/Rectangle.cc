#include "Rectangle.h"

//The constructor of class Rectangle first invokes the constructor of parent 
//class 'Shape' by forwarding argument 'name into it. We do that by writing
//": Shape (name)" between the function header and the "{" symbol.
Rectangle::Rectangle(std::string name, float width, float height) : Shape(name)
{
	this->width = width;
	this->height = height;
}
