#include "hangman.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string>

using namespace std;

void hangingMan (int hang)
{
	if (hang == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;//the hanging man thing is 9 lines in total
	}
	else if (hang == 1)
	{

	}//etc.
}

void prettyYouWinText()
{
	cout << "."; //text out of dashes or sth that says "You win!"
}

void prettyYouLoseText()
{
	cout << "."; //text out of dashes or sth that says "You lose!"
}

void menu1()
{
	cout << "1.Guess a letter" << endl;
	cout << "2.Guess the whole word" << endl << endl;
}

int hangman ()
{
	string wordToBeGuessed;
	char wordNow[50];

	cout << "Enter a word to be guessed: ";
	cin >> wordToBeGuessed;
	system("CLS"); //clear screen


	int wordLen = wordToBeGuessed.size();
	for (int i = 0; i < wordLen; i++)
	{
		wordNow[i] = '*';
	}

	char wrongLetters[40];
	int hang = 0; //counts the wrongly guessed letters
	int option; //the user chooses what to enter
	bool guess; //checks if the guess is right of wrong
	char letterGuess;
	string wordGuess;
	bool checkStar = false;

	while (true)
	{
		hangingMan(hang);

		for (int i = 0; i < wordLen; i++)
		{
			cout << wordNow[i] << " ";
		}
		cout << endl;

		if (hang == 9) //if the hanging man is coplete the player loses
		{
			prettyYouLoseText(); //cout << "You lose!" << endl;
			return 0;
		}

		menu1();
		
		cout << "Enter number: ";
		cin >> option;

		guess = false;
		checkStar = false;

		if (option == 1) //if the user chooses to enter a letter
		{
			cout << "Enter a letter: ";
			cin >> letterGuess;

			for (int i = 0; i < wordLen; i++)
			{
				if (letterGuess == wordToBeGuessed[i])
				{
					guess = true;
					wordNow[i] = letterGuess; //add letter to thing
				}
			}

			if (guess == true)
			{
				for (int i = 0; i < wordLen; i++)
				{
					if (wordNow[i] == "*")
					{
						checkStar = true;
					}
				}

				if (checkStar == true)
				{
					cout << "Correct!" << endl;
				}
				else
				{
					prettyYouWinText(); //cout << "You win!" << endl;
					return 0;
				}
			}
			else
			{
				hang++;
				cout << "Nope :(" << endl;
			}
		}

		else if (option == 2) //if the user chooses to try to guess the whole word
		{
			cout << "Enter a word: ";
			cin >> wordGuess;

			if (wordGuess.compare(wordToBeGuessed) == 0)
			{
				guess = true;
			}

			if (guess == true)
			{
				prettyYouWinText(); //cout << "You win!" << endl;
				return 0;
			}
			else
			{
				hang++;
				cout << "Nope :(" << endl;
			}
		}

		system("CLS"); //clear screen
	}
}