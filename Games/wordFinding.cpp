#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include "wordFinding.h"
#include "frontEnd.h"

using namespace std;


//word bank
string words[10] = { "umbrella", "spinach", "knowledge", "conflict", "ancient", "wealthy", "rainbow", "furious", "olive", "resources" };
char box[10][10];

int wordFinding()
{
	int times = 0;
	int win = 0;
	int lose = 0;

	while (times < 3)
	{
		times++;

		//generate a random number
		srand(time(NULL));

		//fill box with letters
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				do
				{
					box[i][j] = rand();
				} while (!(box[i][j] >= 97 && box[i][j] <= 122));
			}
		}

		//choose a random position for the first letter of the word
		int position = rand() % 10;
		int row = 0, column = 0;

		//choose word orientation
		if (words[position].size() % 2 != 0)
		{
			row = rand() % 10;
			column = rand() % 2;

			//print word
			for (int i = 0; words[position][i] != '\0'; i++)
			{
				column++;
				box[row][column] = words[position][i];
			}
		}
		else
		{
			row = rand() % 2;
			column = rand() % 10;

			//print word
			for (int i = 0; words[position][i] != '\0'; i++)
			{
				row++;
				box[row][column] = words[position][i];
			}
		}

		//print box
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << box[i][j] << " ";
			}
			cout << endl;
		}

		string guess;
		cout << endl;
		cout << "Enter a word of " << words[position].size() << " length: ";
		cin >> guess;
		if (guess == words[position])
		{
			cout << "\nCorrect!\n" << endl;
			win++;
		}
		else
		{
			cout << "\nNope :(" << endl;
			cout << "\nThe correct word was " << words[position] << endl <<endl;
			lose++;
		}

		system("pause");
		//clear screen
		system("CLS"); 
	}

	if (win >= 2)
	{
		youWin();
	}
	else
	{
		youLose();
	}

	return 0;
}