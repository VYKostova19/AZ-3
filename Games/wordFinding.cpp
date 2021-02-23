#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include "wordFinding.h"
#include "frontEnd.h"



std::string words[10] = { "umbrella", "spinach", "knowledge", "conflict", "ancient", "wealthy", "rainbow", "furious", "olive", "resources" };
char box[10][10];

int wordFinding()
{
	int times = 0;
	int win = 0;
	int lose = 0;

	while (times < 3)
	{
		times++;

		srand(time(NULL));
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

		int position = rand() % 10;
		int row = 0, column = 0;

		if (words[position].size() % 2 != 0)
		{
			row = rand() % 10;
			column = rand() % 2;

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

			for (int i = 0; words[position][i] != '\0'; i++)
			{
				row++;
				box[row][column] = words[position][i];
			}
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cout << box[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::string guess;
		std::cout << std::endl;
		std::cout << "Enter a word of " << words[position].size() << " length: ";
		std::cin >> guess;
		if (guess == words[position])
		{
			std::cout << "Correct!" << std::endl;
			win++;
		}
		else
		{
			std::cout << "Nope :(" << std::endl;
			std::cout << "The correct word was " << words[position] << std::endl;
			lose++;
		}

		system("pause");
		system("CLS"); //clear screen
	}

	if (win >= 2)
	{
		std::cout << "You win!" << std::endl;
	}
	else
	{
		std::cout << "You lose :(" << std::endl;
	}

	return 0;
}