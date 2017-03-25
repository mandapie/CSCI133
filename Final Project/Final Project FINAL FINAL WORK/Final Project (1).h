/*Group Amanda Pan, Carissa Kane, Viraat Udar
Visual Studio 2010
Final Project*/

#pragma once

const int tablesize = 1009;

class unscrambler
{
	struct word
	{
		char name[35];
		word *link;
	};
	word *nodeptr;
	word *newWord;
	word *answer;
	string dict[113];
//	int counter[1009];
	int count;
	word *hashy[1009]; //word** hashy; 

public:
	unscrambler();
	void ImportDictionary();
	void EnterWord();
	void AddWord();
	void ShowWord();
	void ShowDictionary();
	int myHash(char *haha);
};