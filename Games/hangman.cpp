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
		cout << "nishto" << endl;//the hanging man thing is 9 lines in total
	}
	else if (hang == 1)
	{
		cout << "1 greshka" << endl;
	}//etc.
	else if (hang == 2)
	{
		cout << "2 greshka" << endl;
	}
	else if (hang == 3)
	{
		cout << "3 greshka" << endl;
	}
	else if (hang == 4)
	{
		cout << "4 greshka" << endl;
	}
	else if (hang == 5)
	{
		cout << "5 greshka" << endl;
	}
	else if (hang == 6)
	{
		cout << "6 greshka" << endl;
	}
	else if (hang == 7)
	{
		cout << "7 greshka" << endl;
	}
	else if (hang == 8)
	{
		cout << "8 greshka" << endl;
	}
	else if (hang == 9)
	{
		cout << "9 greshka" << endl;
	}
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
	cout << endl;
	cout << "1.Guess a letter" << endl;
	cout << "2.Guess the whole word" << endl;
	cout << "3.Joker" << endl << endl;
}

int hangman ()
{
	string wordToBeGuessed;
	char wordNow[50];
	char wrongCh[50];
	int countWrongCh = 0;
	char jokerLetter;

	cout << "Enter a word to be guessed: ";
	cin >> wordToBeGuessed;
	system("CLS"); //clear screen


	size_t wordLen = wordToBeGuessed.size();
	for (size_t i = 0; i < wordLen; i++)
	{
		wordNow[i] = '*';
	}

	wordNow[0] = wordToBeGuessed[0];
	//for (size_t i = 0; i < wordLen; i++)
	//{
	//	if (wordNow[i] == wordToBeGuessed[0])
	//	{
	//		wordNow[i] = wordToBeGuessed[0];
	//	}
	//}

	int hang = 0; //counts the wrongly guessed letters
	int option; //the user chooses what to enter
	bool guess; //checks if the guess is right of wrong
	char letterGuess;
	string wordGuess;
	bool checkStar = false;
	bool clearScr = false;
	bool checkChoice = true;

	while (true)
	{
		hangingMan(hang);

		for (size_t i = 0; i < wordLen; i++)
		{
			cout << wordNow[i] << " ";
		}
		cout << endl;

		if (hang == 9) //if the hanging man is coplete the player loses
		{
			//prettyYouLoseText(); //
			cout << "You lose!" << endl;
			return 0;
		}

		cout << "Incorrectly chosen letters: ";
		if (countWrongCh != 0)
		for (int i = 0; i < countWrongCh; i++)
		{
			cout << wrongCh[i] << " ";
		}
		menu1();
		
		// napravi proverka !!!!
		//while (checkChoice)
		//{
			cout << "Enter number: ";
			cin >> option;

			//if (option == 1 || option == 2)
			//{
			//	checkChoice = false;
			//}
			//else
			//{
			//	cout << "Invalid number!" << endl;
			//}
		//}
		

		guess = false;
		checkStar = false;
		

		if (option == 1) //if the user chooses to enter a letter
		{
			cout << "Enter a letter: ";
			cin >> letterGuess;

			for (size_t i = 0; i < wordLen; i++)
			{
				if (letterGuess == wordToBeGuessed[i])
				{
					guess = true;
					wordNow[i] = letterGuess; //add letter to thing
				}
			}

			if (guess == true)
			{
				for (size_t i = 0; i < wordLen; i++)
				{
					if (wordNow[i] == '*')
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
					//prettyYouWinText(); //
					cout << "You win!" << endl;
					return 0;
				}
			}
			else
			{
				hang++;
				wrongCh[countWrongCh] = letterGuess;
				countWrongCh++;
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
				//prettyYouWinText(); //
				cout << "You win!" << endl;
				return 0;
			}
			else
			{
				hang++;
				cout << "Nope :(" << endl;
			}
		}

		else if (option == 3) //joker
		{
			for (size_t i = 0; i < wordLen; i++)
			{
				if (wordNow[i] == '*')
				{
					wordNow[i] = wordToBeGuessed[i];
					jokerLetter = wordToBeGuessed[i];
					i = 100;
				}
			}

			for (size_t i = 0; i < wordLen; i++)
			{
				if (wordNow[i] == '*' && wordToBeGuessed[i] == jokerLetter)
				{
					wordNow[i] = jokerLetter;
				}
			}
		}

		cout << "Enter 1 to continue" << endl;
		cin >> clearScr;

		if (clearScr)
		{
			system("CLS"); //clear screen
		}

	}
}