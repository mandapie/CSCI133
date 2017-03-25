/*
Name: Amanda Pan
Class: CSCI 133
CRN: 24229
Compiler: VS 2012
Homework: 2
Due: 03/19/15
Project: Implementing auto parts PART 2
*/

#include <iostream>
using namespace std;
#include "HW 2.h"

int main()
{
	AutoParts obj;
	char ans1, loop1 = 'y';

	while (loop1 == 'y')
	{
		cout << "(E)nter - This will enter complete part information.\n";
		//cout << "(S)earch - Will alow the user to search for a particular part number.\n";
		cout << "(D)isplay - Display all items in the database.\n";
		cout << "(C)lear - Clear the entire databaseout to nulls.\n";
		cout << "(Q)uit.\n\n";
		cin >> ans1;
		cout << endl;
		cin.ignore();

		switch (ans1)
		{
			case 'E':
			case 'e':
				obj.Enter();
				break;
			/*
			case 'S':
			case 's':
				obj.Search();
				break;
			*/
			case 'D':
			case 'd':
				obj.Display();
				break;
			case 'C':
			case 'c':
				obj.Clear();
				break;
			case 'Q':
			case 'q':
				loop1 = 'n';
				break;
			default:
				cout << "Pick 'E', 'S', 'D', 'C', or 'Q' only\n\n";
		}		
	}
	system ("pause");
	return 0;
}

void AutoParts :: Enter()
{
	if(Entrees < MAX)
	{
		newNode = new Database;
	
		cout << "Enter part number: ";
			cin.getline(newNode->PartNumber, sizeof(newNode->PartNumber));
	
		cout << "Enter part description: ";
		cin.getline(newNode->PartDescription, sizeof(newNode->PartDescription));
		
		cout << "Enter Make of vehicle for part: ";
		cin.getline(newNode->Make, sizeof(newNode->Make));
		
		cout << "Enter Model of vehicle: ";
		cin.getline(newNode->Model, sizeof(newNode->Model));
	
		cout << "Enter Engine Type: ";
		cin.getline(newNode->EngineType, sizeof(newNode->EngineType));
		
		cout << "Enter year(YYYY format): ";
		cin.getline(newNode->Year, sizeof(newNode->Year));
		cout << endl;

		Entrees ++;
		
		newNode->nextStruct = NULL;  //newNode(ptr) points to nextStruct(ptr) that points to a new struct becomes NULL
		
		if(head == NULL)
			head = newNode;
		else
		{
			nodeptr = head;
			
			while(nodeptr->nextStruct != NULL)
				nodeptr = nodeptr->nextStruct;
			
			nodeptr->nextStruct = newNode;
		}
		
		/* This is adding adding new node at the last one
		if(head == NULL)
			head = newNode; //points to newNode(ptr)
		else
		{
			newNode->nextStruct = head;
			head = newNode;
		}*/
	}
	else
	{
		cout << "\nYou have reached maximum entrees\n\n";
		return;
	}
}

void AutoParts :: Display()
{
	nodeptr = head; //points to the head ptr to set up printing
	
	if(nodeptr == NULL)
	{
		cout << "No data to display\n\n";
		return;
	}

	while(nodeptr != NULL)
	{	 
		cout << "PartNumber: " << nodeptr->PartNumber << "\n";
		cout << "PartDescription: " << nodeptr->PartDescription << "\n";
		cout << "Make: " << nodeptr->Make << "\n";
		cout << "Model: "<< nodeptr->Model << "\n";
		cout << "EngineType: " << nodeptr->EngineType << "\n";
		cout << "Year: " << nodeptr->Year << "\n\n";
		nodeptr = nodeptr->nextStruct; //points to new nextStruct(pointer to struct)
	}
	
}

void AutoParts :: Clear()
{
	if(head == NULL)
	{
		cout << "No data to clear\n\n";
		return;
	}
	
	else
	{		
		for(int i = Entrees; i == 0 ; i--)
		{
			temp = head; //set temp ptr to head of the list

			while(temp->nextStruct != NULL)
			{
				previous = temp;
				temp = temp->nextStruct;
			}
			previous->nextStruct = NULL; //temp->nextStruct; //Link the previous node to the node after the node ptr
			delete temp;
		}
		head = NULL;
		Entrees = 0;
	}
	/*
	while(nodeptr->next != NULL) //clears struct datas in the link list BUT SOMEHOW IT'S NOT WORKING
	{
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 21; j++)
				nodeptr->PartNumber[j] = NULL;

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 31; j++)
				nodeptr->PartDescription[j] = NULL;

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 21; j++)
				nodeptr->Make[j] = NULL;

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 7; j++)
				nodeptr->Model[j] = NULL;

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < 5; j++)
				nodeptr->Year[j] = NULL;
		
		nodeptr = nodeptr->next;
	}
	
	head = NULL; //sets to new struct link list
	*/
	cout << "database cleared\n\n";
}
/*
void AutoParts :: Search()
{

}
*/