#include <iostream>

struct Person
{
	//Information about person
	std::string name;
	int age;
	int ID;

	//Pointer to next person in the list
	Person *next;
};

struct List
{
	//First person in the list. A null pointer indicates that the list is
	//empty.
	Person *head;

	//Current node in the list. A null pointer indicates a past-the-end
	//position
	Person *current;

	//Pointer to the element appearing before 'current', or null if
	//'current' is the first element, or the list is empty.
	Person *previous;
};

//Prints out a person's ID, name, and age
void PrintPerson(Person *p){
	std::cout << "Person " << p->ID << " is named " << p->name << " and is " << p->age << " years old.\n";
}

void ListInitialize(List *list)
{
	list->head = NULL;
	list->current = NULL;
	list->previous = NULL;
}

void ListHead(List *list)
{
	list->current = list->head;
	list->previous = NULL;
}

void ListNext(List *list)
{
	//This is equivilent to "if (list->current != nullptr)"
	if(list->current)
	{
		list->previous = list->current;
		list->current = list->current->next;
	}
}

//Set the current position to the person with the given name.If no person
//exists with that name, the current position is set to past-the-end.
void ListFind(List *list, int id)
{
	ListHead(list);
	while(list->current && list->current->ID != id)
		ListNext(list);

	if(list->current)
		PrintPerson(list->current);
	else
		std::cout << "Invalid ID\n";
}

//Insert a person before the element at the current position in the list.
//If the current position is past-the-end, the person is inserted at the
//end of the list. The new person is made the new current element in the list.
void ListInsert(List *list, Person *person)
{
	//Set the 'next' pointer of the new element
	person->next = list->current;

	//Set the 'next' pointer of the previous element if we are not
	//inserting at the head. Update the 'head' pointer of the list if we 
	//are inserting at the head.
	if(list->current == list->head)
		list->head = person;
	else
		list->previous->next = person;

	//Set the current element to the new person
	list->current = person;
}

//Remove the current element in the list. The new current element will be
//the element that appeared right after the removed element.
void ListRemove(List *list)
{
	//Ignore this call if the current element is past-the-end
	if(!list->current)
		return;

	//Remove the element. Consider the special case where the current element
	//is at the head of the list.
	if(list->current == list->head)
		list->head == list->current->next;
	else
		list->previous->next = list->current->next;

	//Save a reference to the element appearing after the current element
	Person *next = list->current->next;

	//Free memory for the removed element
	delete list->current;

	//Turn the element that came after the removed element into the 
	//current element
	list->current = next;

	std::cout << "Element removed\n";
}

void ReadPerson(List *list, int counter)
{
	Person *p = new Person;

	//Read name
	std::cout << "Enter name: ";
	std::cin >> p->name;

	//Read age
	std::cout << "Enter age: ";
	std::cin >> p->age;

	p->ID = counter;

	std::cout << p->name << " is " << p->age << " years old.\n";

	ListInsert(list, p);
}

//Sorts by age or name
void SortList(List *list, int count)
{
	int sortBy = 0;
	std::cout << "Sort by \n"
		  << "1) Name \n"
		  << "2) Age \n"
		  << "Input: ";

	while(sortBy != 1 && sortBy != 2)
	{
		std::cin >> sortBy;

		if(sortBy != 1 && sortBy != 2)
			std::cout << "Invalid choice";
	}

	std::string tempName;
	int tempAge;
	//Sort By Name
	if(sortBy == 1)
	{
		Person *v[count];
		if(count > 0)
		{
			ListHead(list);
			for(int i = 0; i < count; i++)
			{
				v[i] = list->current;
				ListNext(list);
			}
			
			for(int i = 0; i < count; i++)
			{
				for(int j = 0; j < count; j++)
				{
					std::string s1 = v[j]->name;
					std::string s2 = v[i]->name;
					if(s1.compare(s2) < 0)
					{
						tempName = v[i]->name;
						v[i]->name = v[j]->name;
						v[j]->name = tempName;

						tempAge = v[i]->age;
						v[i]->age = v[j]->age;
						v[j]->age = tempAge;
					}
				}
			}

		}
	}

	if(sortBy == 2)
	{
		Person *v[count];
		if(count > 0)
		{
			ListHead(list);
			for(int i = 0; i < count; i++)
			{
				v[i] = list->current;
				ListNext(list);
			}
			
			for(int i = 0; i < count; i++)
			{
				for(int j = 0; j < count; j++)
				{
					int a1 = v[j]->age;
					int a2 = v[i]->age;
					if(a2 < a1)
					{
						tempName = v[i]->name;
						v[i]->name = v[j]->name;
						v[j]->name = tempName;

						tempAge = v[i]->age;
						v[i]->age = v[j]->age;
						v[j]->age = tempAge;
					}
				}
			}

		}

	}
}

int main()
{
	List *list = new List;
		
	ListInitialize(list);
	int choice = 0;
	//Tracks people added
	int counter = 0;
        while(choice != 5){
		 std::cout << "Main menu: \n"
		 	 << "1. Add a person \n"
			 << "2. Find a person \n"
			 << "3. Remove a person \n"
			 << "4. Print the list \n"
			 << "5. Sort the list \n"
			 << "6. Exit \n\n"
			 << "Select an option: ";

                //User input
                std::cin >> choice;

		//Checks invalid
                if(choice < 1 || choice > 6)
			std::cout << "Invalid input";

                std::cout << '\n';
		 
		int ID = 0;
		switch(choice) {
        		case 1:
				counter++;
				ReadPerson(list, counter);
				break;
	        	case 2:
	               		std::cout << "Enter the person's ID: ";
				std::cin >> ID;
				ListFind(list, ID);		
				break;
                	case 3:
                        	std::cout << "Enter the person's ID: ";
				std::cin >> ID;
				ListFind(list, ID);
				if(list->current)
					ListRemove(list);
				break;
	        	case 4:
				ListHead(list);
				for(int i = 0; i < counter; i++)
				{
					PrintPerson(list->current);
					ListNext(list);
				}
				break;
			case 5:
				SortList(list, counter);
				break;
			case 6:

				return 0;
			default:
		        	break;
		}

		choice = 0;
	}

	//End
	return 0;

}
