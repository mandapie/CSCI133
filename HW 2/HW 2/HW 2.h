/*
Name: Amanda Pan
Class: CSCI 133
Compiler: VS 2012
CRN: 24229
Homework: 2
Due: 03/19/15
Project: Implementing auto parts PART 2
*/

#pragma once

const int MAX = 50;

class AutoParts
{
	int Entrees;
	
	struct Database
	{
		char PartNumber[21];
		char PartDescription[31];
		char Make[21];
		char Model[21];
		char EngineType[7];
		char Year[5];
		struct Database *nextStruct;
	};

	Database *head, *newNode, *nodeptr, *temp, *previous;

public:
	AutoParts()
	{
		Entrees = 0;
		head = NULL;
	}

	void Initial();
	void Enter();
	//void Search();
	void Display();
	void Clear();
};