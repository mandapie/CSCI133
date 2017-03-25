/*
Name: Amanda Pan
Class: CSCI 133
CRN: 24229
Compiler: VS 2012
Homework: 3
Due: 04/09/15
Project: Implementing auto parts PART 3
*/

#include <iostream>
using namespace std;
#include "HW 3.h"

int main()
{
	AutoParts obj;
	char ans1, loop1 = 'y';

	while (loop1 == 'y')
	{
		cout << "(E)nter - This will enter complete part information.\n";
		cout << "(S)earch - Search for a particular part number.\n";
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
			
			case 'S':
			case 's':
				obj.Search();
				break;
			
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
		newNode = new NODE;
	
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
	}
	else
	{
		cout << "You have reached maximum entrees\n\n";
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
			previous->nextStruct = temp->nextStruct; //Link the previous node to the node after the node ptr
			delete temp;
		}
		head = NULL;
		Entrees = 0;
	}
	cout << "database cleared\n\n";
}

void AutoParts :: Search()
{
	char searchptnum[21], answer;
	int match = 0;
	search = head;

	if(search == NULL)
	{
		cout << "There is nothing to search" << "\n\n";
		return;
	}

	cout << "Enter part number to search: ";
	cin.getline(searchptnum,sizeof(searchptnum));
	cout << "\n";
	long double hashvalue = hash(searchptnum);
/*
	while(search != NULL)
	{
		int j = 0;
		int k = 0;
		while(searchptnum[j] != NULL)
		{
			for(int i = 0; i < sizeof(searchptnum);i++)
			{
				if(searchptnum[i] == search->PartNumber[i] && searchptnum[i] == NULL && searchptnum[k] == NULL)
				{
					cout << "PartNumber: " << search->PartNumber << "\n";
					cout << "PartDescription: " << search->PartDescription << "\n";
					cout << "Make: " << search->Make << "\n";
					cout << "Model: "<< search->Model << "\n";
					cout << "EngineType: " << search->EngineType << "\n";
					cout << "Year: " << search->Year << "\n\n";
				}
				k++;
			}
			j++;
		}
		search = search->nextStruct; //points to new nextStruct(pointer to struct)
	}
*/
	while(search != NULL)
	{
		if(hashvalue == hash(search->PartNumber))
		{
			match++;
		}
				
		search = search->nextStruct;
	}
	while(search != NULL)
	{
		if(hashvalue == hash(search->PartNumber))
		{
			if(match <= 1)
			 {
				cout << match << " match found:\n";
				cout << "PartNumber: " << search->PartNumber << "\n";
				cout << "PartDescription: " << search->PartDescription << "\n";
				cout << "Make: " << search->Make << "\n";
				cout << "Model: "<< search->Model << "\n";
				cout << "EngineType: " << search->EngineType << "\n";
				cout << "Year: " << search->Year << "\n\n";
			}
			else if(match > 1)
			{
				cout << match << " matches found. Would you like to display all of them?(Y/N)\n";
				cin >> answer;
				switch(answer)
				{
				case 'y':
				case 'Y':
					cout << match << " match found:\n";
					cout << "PartNumber: " << search->PartNumber << "\n";
					cout << "PartDescription: " << search->PartDescription << "\n";
					cout << "Make: " << search->Make << "\n";
					cout << "Model: "<< search->Model << "\n";
					cout << "EngineType: " << search->EngineType << "\n";
					cout << "Year: " << search->Year << "\n\n";
					break;
				case 'n':
				case 'N':
					cout << "How many do you want to display?\n";
					break;
				default:
					cout << "Pick 'y' or 'n' only\n\n";
				}
			}
			search = search->nextStruct;
		}
		if(match == 0)
			cout << "no match found\n";
	}
}

long double AutoParts :: hash(char *value)
{
	int j = 0;
	for(int i = 0; i < sizeof(value); i++)
		j += num^tablesize*(value[i]);
	return j;
}