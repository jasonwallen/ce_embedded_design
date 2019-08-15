#include <iostream>

struct Person
{
	//Information about person
	std::string name;
	int age;

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

void ListInitialize(List *list)
{
	list->head = nullptr;
	list->current = nullptr;
	list->previous = nullptr;
}

void ListHead(List *list)
{
	list->current = list->head;
	list->previous = nullptr;
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
void ListFind(List *list, std::string name)
{
	ListHead(list);
	while(list->current && list->current->name != name)
		ListNext(list);
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
}

int main()
{

}
