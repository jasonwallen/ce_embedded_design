#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
	//Swap values
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	//Read first value
	int a;
	cout << "Enter first value: ";
	cin >> a;

	//Read second value
	int b;
	cout << "Enter second value: ";
	cin >> b;

	//Swap them
	Swap(a,b);

	//Print values
	cout << "The swapped values are: " << a << " " << b << '\n';
	
	//End
	return 0;
}
