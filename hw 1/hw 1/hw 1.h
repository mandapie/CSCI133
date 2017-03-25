/*
Name: Amanda Pan
Class: CSCI 133
Compiler: VS 2012
Homework: 1
Due: 02/18/15
Project: Implementing auto parts
*/

#pragma once

const int MAX = 50;

class AutoParts
{
	int Entrees;

public:
	struct P
	{
	char PartNumber[21];
	char PartDescription[31];
	char Make[21];
	char Model[21];
	char EngineType[7];
	char Year[5];
	};

	P array[MAX];

	void Initial();
	void Enter();
	//void Search();
	void Display();
	void Clear();
};

