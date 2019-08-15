#include <iostream>

void Mirror(int v[], int n)
{
	// Traverse the array
	for(int i = 0; i < n/2; i++)
	{
		// Exchange elements 'i' and 'n-i-1'
		int temp = v[i];
		v[i] = v[n-i-1];
		v[n-i-1] = temp;
	}
}

int main()
{
	// Declare array
	int v[] = {5, 6, 7, 8, 2, 1};
	
	// Mirror
	Mirror(v, 6);

	// Print the array
	for(int i = 0; i < 6; i++)
		std::cout << v[i] << '\n';

	// End
	return 0;
}
