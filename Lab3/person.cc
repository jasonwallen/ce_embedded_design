#include <iostream>

struct Person
{
	std::string name;
	int age;
};

void PrintPerson(Person *pp)
{
	std::cout << "Name: " << pp->name << '\n';
	std::cout << "Age: " << pp->age << '\n';
	std::cout << '\n';
}

void ReadPerson(Person *pp)
{
	//Read name
	std::cout << "Enter name: ";
	std::cin >> pp->name;

	//Read age
	std::cout << "Enter age: ";
	std::cin >> pp->age;
}

int main()
{
	
	PrintPerson(NULL);

	//Request value of n
	int n;
	std::cout << "Enter number of persons: ";
	std::cin >> n;

	//Allocate array of persons
	Person **v = new Person*[n];

	//Allocate and read persons
	for(int i = 0; i < n; i++)
	{
		//v is of type Person**
		//v[i] is of type Person*
		//'new Person' returns type Person*
		v[i] = new Person;
		ReadPerson(v[i]);
	}

	//Print persons
	for (int i = 0; i < n; i++)
	{
		std::cout << "Person " << i << ":\n";
		PrintPerson(v[i]);

		//Free person
		delete v[i];
	}

	//Free array
	delete[] v;

	//End
	return 0;
}
