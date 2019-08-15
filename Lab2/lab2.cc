#include <iostream>

double *v;
int count;
int size;

void Initialize()
{
	v = new double[2];
	count = 0;
	size = 2;
}

void Finalize()
{
	delete v;
}

void Grow()
{
	//Declare new pointer
	double *nv;
	nv = new double[size*2];

	//Set nv equal to v
	for(int i = 0; i < size; i++)
		nv[i] = v[i];

	//Free v
	delete []v;
	//Set v to point to nv
	v = nv;
	
	//Print debug info
	std::cout << "Vector grown\n";
	std::cout << "Previous capacity: " << size << " elements\n";
	std::cout << "New capacity: " << size*2 << " elements\n";
	size *= 2;
}

void AddElement()
{
	double element;

	//Grow vector if necessary
	if(count == size)
		Grow();
	
	//Enter message and user input
	std::cout << "Enter the new element: ";
	std::cin >> element;

	//Appends element
	*(v+count) = element;
	count++;

}

void PrintVector()
{
	//Transverse array
	for(int i = 0; i < count; i++)
		std::cout << v[i] << " ";
	std::cout << '\n';
}

void RemoveElement()
{
	//Error message
	if(count == 0)
		std::cout << "No elements to remove \n";
	else
		count--;
}

void InsertElement()
{
	int index;
	double element;

	//Ask for index and element from user
	//Index should be array index
	std::cout << "Enter the index of new element: ";
	std::cin >> index;
	
	std::cout << "Enter the new element: ";
	std::cin >> element;

	if(index > count || index < 0)
		std::cout << "Invalid index\n";
	else
	{
		if(count >= size)
			Grow();
		for(int i = count; i > index; i--)
		{
			v[i] = v[i-1];
		}
		v[index] = element;
		count++;

	}
}

void Shrink()
{
	if(count <= (.3*size))
	{
		double *nv;
		nv = new double[size/2];

		delete []v;
		v = nv;

		std::cout << "The vector has shrunk.\n";
		size /= 2;
	}
	std::cout << "The size is now " << size << " with " << count << " elements.\n";
	
}

int main()
{
	Initialize();

	//Menu
	int choice = 0;
	while(choice != 5){
		std::cout << "Main menu: \n"
		     << "1. Print the array \n"
		     << "2. Append element at the end \n"
		     << "3. Remove last element \n"
		     << "4. Insert one element \n"
		     << "5. Exit \n\n"
		     << "Select an option: ";
			
		//User input
		std::cin >> choice;
				

		if(choice < 1 || choice > 5)
			std::cout << "Invalid input";
	
		std::cout << '\n';

		switch(choice) {
			case 1:
				std::cout << "You have selected \"Print the array\"\n";
				PrintVector();
				break;
			case 2:
				std::cout << "You have selected \"Append element at the end\"\n";
				AddElement();
				break;
			case 3:
				std::cout << "You have selected \"Remove last element\"\n";
				RemoveElement();
				if(count != 0)
					Shrink();
				break;
			case 4:
				std::cout << "You have selected \"Insert one element\"\n";
				InsertElement();
				break;
			case 5:
				return 0;
			default:
				break;
		}
		
		choice = 0;
	}	
	std::cout << '\n';
	
	//End
	Finalize();
	return 0;
}
