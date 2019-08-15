#include "Rectangle.h"

int main()
{
	//Static instantiation of rectangle
	Rectangle r("Static Rectange");

	//Call class functions
	r.setDimensions(2.2, 3.3);
	std::cout << "Area of static rectangle: " << r.getArea() << '\n';

	//End
	return 0;

	//NOTE: Implicit invokation to destructor 
	//'Rectangle::~Rectangle()' here, when local variable
	//'r' disappears.
}
