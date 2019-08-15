#include "Rectangle.h"

int main()
{
	//1. Allocate memory dynamically
	//2. Invoke constructor
	Rectangle *r = new Rectangle("Dynamic Rectangle");

	//Call class functions
	r->setDimensions(4.4, 5.5);
	std::cout << "Area of Dynamic Rectangle: " << r->getArea() << '\n';

	//1. Invoke the destructor
	//2. Free the memory
	delete r;

	//End
	return 0;
}
