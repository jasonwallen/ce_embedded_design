#include <iostream>
#include <stdlib.h>
#include <ctime>

void PrintArray(int v[], int size)
{
	//Traverse the array
	for(int i = 0; i < size; i++)
	{
		//Print the element at index 'i'
		std::cout << v[i] << ' ' << '\n';
	}
}

void RandomArray(int v[], int size)
{
	//Traverse the array
	for(int i = 0; i < size; i++)
	{	
		//Insert random numbers in the array
		v[i] = rand()%99;
	}
}

void SortArray(int v[], int size)
{
	int temp;
	//Traverse the array
	for(int i = 0; i < size; i++)
	{
		//Traverse the rest of the array to compare values to index 'i'
		for(int j = i; j < size; j++)
		{
			//Compare the values at the two indicies
			if(v[j] < v[i])
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

int main()
{
	//Set a new seed for the rand() function
	srand(time(0));
	
	//Initialize the array
	int v[10];

	//Fill array with random values between 0 and 99
	RandomArray(v, 10);
	//Sort the array
	SortArray(v, 10);
	//Print the array
	PrintArray(v, 10);

	return 0;
}
