/*
Name: Amanda Pan
Class: CSCI 133
Compiler: VS 2012
Homework: 1
Due: 02/18/15
Project: Implementing auto parts
*/

#include <iostream>
using namespace std;
#include "hw 1.h"

int main()
{
	AutoParts obj;
	char ans1, loop1 = 'y';

	obj.Initial();

	while (loop1 == 'y')
	{
		cout << "(E)nter - This will enter complete part information.\n";
		//cout << "(S)earch - Will alow the user to search for a particular part number.\n";
		cout << "(D)isplay - Display all items in the database.\n";
		cout << "(C)lear - Clear the entire databaseout to nulls.\n";
		cout << "(Q)uit.\n";
		cin >> ans1;
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

void AutoParts :: Initial() //set everything to null
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 21; j++)
			array[i].PartNumber[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 31; j++)
			array[i].PartDescription[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 21; j++)
			array[i].Make[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 7; j++)
			array[i].Model[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 5; j++)
			array[i].Year[j] = NULL;
}

void AutoParts :: Enter()
{
	Entrees = 1;
	P newset;
	char ans2, loop2 = 'y';

	
	//cin.getline() doesn't work. I don't know why.

	while(loop2 == 'y')
	{
		cout << "Enter part number: ";
		cin >> newset.PartNumber;
		//cin.getline(newset.PartNumber, sizeof(newset.PartNumber));
		cin.ignore();

		cout << "Enter part description: ";
		cin >> newset.PartDescription;
		//cin.getline(newset.PartDescription, sizeof(newset.PartDescription));
		cin.ignore();

		cout << "Enter Make of vehicle for part: ";
		cin >> newset.Make;
		//cin.getline(newset.Make, sizeof(newset.Make));
		cin.ignore();

		cout << "Enter Model of vehicle: ";
		cin >> newset.Model;
		//cin.getline(newset.Model, sizeof(newset.Model));
		cin.ignore();

		cout << "Enter Engine Type: ";
		cin >> newset.EngineType;
		//cin.getline(newset.EngineType, sizeof(newset.EngineType));
		cin.ignore();

		cout << "Enter year(YYYY format): ";
		cin >> newset.Year;
		//cin.getline(newset.Year, sizeof(newset.Year));
		cin.ignore();
		
		array[Entrees] = newset;
		Entrees++;

		cout << "Enter another Part Number? (Y/N)\n";
		cin >> ans2;
		
		switch(ans2)
		{
			case 'Y':
			case 'y':
				cout << "\n";
				
				if(Entrees >= MAX)
				{
					cout << "You have reached maximum entrees\n\n";
					loop2 = 'n';
				}
				break;
			case 'N':
			case 'n':
				loop2 = 'n';
				break;
			default:
				cout << "'Y' or 'N' only\n";
		}
	}

}

void AutoParts :: Display()
{
	for(int i = 1; i < Entrees; i++)
	{
		cout << "PartNumber: " << array[i].PartNumber << "\n";
		cout << "PartDescription: " << array[i].PartDescription << "\n";
		cout << "Make: " << array[i].Make << "\n";
		cout << "Model: "<< array[i].Model << "\n";
		cout << "EngineType: " << array[i].EngineType << "\n";
		cout << "Year: " << array[i].Year << "\n\n";
	}
}

void AutoParts :: Clear()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 21; j++)
			array[i].PartNumber[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 31; j++)
			array[i].PartDescription[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 21; j++)
			array[i].Make[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 7; j++)
			array[i].Model[j] = NULL;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 5; j++)
			array[i].Year[j] = NULL;

		Entrees = 0;

	cout << "\ndatabase cleared\n\n";
}