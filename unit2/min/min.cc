#include <iostream>

int getMinimum(int v[], int size)
{
	// Initialize minimum value to the first element
	int current_minimum = v[0];

	// Traverse the rest of the array and check for new minimums
	for(int i = 1; i < size; i++)
		if(current_minimum > v[i])
			current_minimum = v[i];

	// Return the minimum
	return current_minimum;
}

int main()
{
	// Declare array
	int v[] = {5, 6, 7, 8, 2, 1};

	// Obtain minimum value
	int result = getMinimum(v, 6);

	// Print result
	std::cout << "The minimum value is " << result << '\n';

	// End
	return 0;
}
