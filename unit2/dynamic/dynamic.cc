#include <iostream>

int main()
{
	//Read number of elements
	int n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;

	//Allocate array of integers dynamically
	int *v = new int[n];

	//Read elements in 'v'
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter element " << i << ": ";
		std::cin >> v[i];
	}	
	
	//Print elements
	for (int i = 0; i < n; i++)
		std::cout << "Element " << i << " is " << v[i] << ". \n";

	//Free array
	delete[] v;

	//End
	return 0;
}
