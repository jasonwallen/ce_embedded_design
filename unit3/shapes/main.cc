#include "Rectangle.h"
#include "Circle.h"

int main()
{
	Circle *c;
	Shape *s;

	//Steps:
	//1. Allocate memory
	//2. Call to constructor Shape::Shape()
	//3. Call to constructor Circle::Circle()
	c = new Circle("My circle", 10);
	
	//Due to polymorphism, this assignment is OK, because every field in
	//'Shape' is also available in 'Circle', and thus, it's safe to 
	//dereference 's' after this.
	s = c;
	
	//Print shape
	s->Print();

	// Print area
	std::cout << "Shape area: " << s->getArea() << '\n';
	
	//Steps:
	//1. Call destructor Circle::~Circle()
	//2. Call destructor Shape::~Shape()
	//3. Free the memory
	delete c;
}
