/*
Name: Amanda Pan
Class: CSCI 133
Compiler: VS 2012
CRN: 24229
Homework: 3
Due: 04/09/15
Project: Implementing auto parts PART 3
*/

#pragma once

const int MAX = 50, tablesize = 347, num = 31;//, hashit = 113;

class AutoParts
{
	int Entrees, tablesize, hashit, num;
	
	struct NODE
	{
		char PartNumber[21];
		char PartDescription[31];
		char Make[21];
		char Model[21];
		char EngineType[7];
		char Year[5];
		struct NODE *nextStruct;
	};

	NODE *head, *newNode, *nodeptr, *temp, *previous, *search;

public:
	AutoParts()
	{
		Entrees = 0;
		head = NULL;
	}

	void Initial();
	void Enter();
	void Search();
	long double hash(char *value);
	void Display();
	void Clear();
};