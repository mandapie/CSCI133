/*Group Amanda Pan, Carissa Kane, Viraat Udar
Visual Studio 2010
Final Project*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
using std::setw;
#include "Final Project (1).h"

int main()
{
	bool redo = true;

	unscrambler beta;
	char decision;
	
	beta.ImportDictionary();

	do
	{
		cout << "(E)nter scrambled word\n(S)how unscrambled word\n(D)isplay dictionary\n(A)dd word to dictionary\n(Q)uit the program\n";
		cin >> decision;
		cin.ignore();
		cout << "\n";

		switch(decision)
		{
			case 'E':
			case 'e':
				beta.EnterWord();
				break;
			case 'S':
			case 's':
				beta.ShowWord();
				break;
			case 'D':
			case 'd':
				beta.ShowDictionary();
				break;
			case 'A':
			case 'a':
				beta.AddWord();
				break;
			case 'Q':
			case 'q':
				redo = false;
				break;
			default:
				cout << "Only enter 'E', 'S', 'D', 'A' or 'Q'.\n\n";
				break;
		};
	}while(redo == true);
	
	system("pause");
	return 0;
}

unscrambler::unscrambler()
{
	count = 0;
	
	for(int i=0; i<tablesize; i++)
		hashy[i] = NULL;
//	for(int h=0; h<1009; h++)
//		counter[h] = 0;
}

void unscrambler::ImportDictionary()
{
	std::ifstream myfile;//("dictionary.txt");
	myfile.open("dictionary.txt", ios::in);
	string buffer;
	int index;

	while(count < 100)
	{
		getline(myfile, buffer);
		dict[count] = buffer;
		count++;

	}
	myfile.close();

	count = 0;
	myfile.open("dictionary.txt", ios::in);
	while(count < 100)
	{
		newWord = new word;
		myfile.getline(newWord->name, sizeof(newWord->name));
		index = myHash(newWord->name);
		newWord->link = NULL;
		nodeptr = hashy[index];

		if(hashy[index] == NULL)
		{
			hashy[index] = newWord;
//			cout << hashy[index]->name << " " << index << "\n";
		}
		else
		{
			while(nodeptr->link != NULL)
				nodeptr = nodeptr->link;
			nodeptr->link = newWord;
//			cout << nodeptr->link->name << " " << index << "\n";
		}
		count ++;
//		counter[index]++;
	}

/*	int x = 0;
	for(int y = 0; y<1009; y++)
	{
		if(counter[y]>1)
			{
				cout << y << ". " << counter[y] << " - ";
				x++;
				cout << x << " \n";
			}
	}
	cout << x << " \n";*/
}

void unscrambler::ShowDictionary()
{
/*	word *buff1 = new word;
	word *buff2;
	word *buff3;*/

	for(int i = 0; i < count; i+=2)
	{
		/*cout << i+1 << ". " << dict[i] << "\n";
		cout << dict[i] << "\t\t" << dict[i+1] << "\t\t" << dict[i+2] << "\n";
		buff1->name = dict[i];
		buff2 = dict[i+1];
		buff3 = dict[i+2];
		printf("%-30p %-30p\n", buff1, buff2);
		printf("%-s %-5s", "frog", buff1);
		cout << dict[i] << "\t\t" << setw(10) << dict[i+1] <<"\t\t" << setw(10) << dict[i+2] << "\n";*/
		cout << setw(32) << dict[i] << setw(32) << dict[i+1] << "\n";
	}
}

void unscrambler::EnterWord()
{
	newWord = new word;
	int index, n, h;
	long scrambled = 0;
	long unscrambled = 0;
	bool correct = false;
	
	cout << "Please enter a scrambled word: ";
	cin.getline(newWord->name,30);
	
	index = myHash(newWord->name);
	answer = hashy[index];
	nodeptr = answer;
	n = strlen(newWord->name);

	for(int i = 0;i < n;i++)
		scrambled += newWord->name[i];

//	cout << scrambled << "\n";

	while (nodeptr && correct == false) 
	{
		h = strlen(nodeptr->name);
		unscrambled = 0;
		for (int i = 0; i < h; i++)
		{
			unscrambled += nodeptr->name[i];
		}

//		cout << unscrambled;

		if(scrambled == unscrambled)
		{
			correct = true;
			answer = nodeptr;
		}
		nodeptr = nodeptr->link;
	}

	if(correct == false)
		answer = NULL;

}

void unscrambler::AddWord()
{
	int index;

	if(count < 113)
	{
		newWord = new word;
		cout << "Please enter a word to add to the dictionary: ";
		cin.getline(newWord->name, sizeof(newWord->name));
		dict[count] = newWord->name;
		index = myHash(newWord->name);
		newWord->link = NULL;
		nodeptr = hashy[index];

		if(hashy[index] == NULL)
			hashy[index] = newWord;
		else
		{
			while(nodeptr->link != NULL)
				nodeptr = nodeptr->link;
			nodeptr->link = newWord;
		}
		
		count++;
	}
	else
	{
		cout << "The dictionary has reached maximum capacity. Dun dun DUUUUN\n\n";
	}
}

void unscrambler::ShowWord()
{
	if (answer != NULL)
		cout << answer->name << "\n\n";

	else
		cout << "This is not a word in the dictionary.\n";
	/*else 
	{
		bool stop = false;
		char decision = 'N';
	
		while(answer && stop == false)
		{
			switch(decision)
			{
				case 'Y':
				case 'y':
					stop = true;
					break;
				case 'N':
				case 'n':
					cout << answer->name << "\n";
					cout << "Please enter a Y or N: ";
					cin >> decision;
					if(decision == 'y' || decision == 'Y')stop = true;
					cout << "\n";
					cin.ignore();
					break;
				default:
					cout << "Please enter a Y or N: ";
					cin >> decision;
					if(decision == 'y' || decision == 'Y')stop = true;
					cout << "\n";
					cin.ignore();
					break;
				
			}
			answer = answer->link;
		}
		if(stop == false && !answer) cout << "No match found.\n\n";
	}*/
}

int unscrambler::myHash(char *haha)
{
	int n = strlen(haha), result;
	long h = 0;
	for(int i = 0;i < n;i++)
		h += (haha[i]*53.97);
	result = (int) h % tablesize;
	return result;
}