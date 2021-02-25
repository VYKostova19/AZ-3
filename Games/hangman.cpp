#include "hangman.h"
#include "frontEnd.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>

using namespace std;

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
		cout << endl << endl;

		if (hang == 9) //if the hanging man is coplete the player loses
		{
			//prettyYouLoseText(); //
			cout << endl << "You lose! The correct word was " << wordToBeGuessed << "." << endl << endl;
			system("pause");
			system("CLS");
			Menu();
			return 0;
		}

		cout << "Incorrectly chosen letters: ";
		if (countWrongCh != 0)
		for (int i = 0; i < countWrongCh; i++)
		{
			cout << wrongCh[i] << " ";
		}
		cout << endl;
		hangmanMenu();
		
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
					cout << endl << "Correct!" << endl << endl;
				}
				else
				{
					//prettyYouWinText(); //
					cout << endl << "You win!" << endl << endl;
					system("pause");
					system("CLS");
					Menu();
					return 0;
				}
			}
			else
			{
				hang++;
				wrongCh[countWrongCh] = letterGuess;
				countWrongCh++;
				cout << endl << "Nope :(" << endl << endl;
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
				cout << endl << "You win!" << endl << endl;
				system("pause");
				system("CLS");
				Menu();
				return 0;
			}
			else
			{
				hang++;
				cout << endl << "Nope :(" << endl;
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

		system("pause");
		system("CLS"); //clear screen
	}
}