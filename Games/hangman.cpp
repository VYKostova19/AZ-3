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
	string wordNow[50];
	char wrongCh[50];
	string asterisk = "*";
	int countWrongCh = 0;
	char jokerLetter;
	int jokerCount = 0;

	cout << "Enter a word to be guessed: ";
	cin >> wordToBeGuessed;

	//clear screen
	system("CLS"); 

	size_t wordLen = wordToBeGuessed.size();
	for (size_t i = 0; i < wordLen; i++)
	{
		wordNow[i] = '*';
	}

	char firstLetter = wordToBeGuessed[0];
	
	//make the first letter appear everywhere
	for (size_t i = 0; i < wordLen; i++)
	{
		if (wordToBeGuessed[i] == firstLetter)
		{
			wordNow[i] = wordToBeGuessed[0];
		}
	}

	//counts the wrongly guessed letters
	int hang = 0; 
	//the user chooses what to enter
	int option; 
	//checks if the guess is right of wrong
	bool guess; 
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
        //if the hanging man is complete the player loses
		if (hang == 9) 
		{
			//prettyYouLoseText(); //
			system("CLS");
			youLose();
			cout << endl << "The correct word was " << wordToBeGuessed << ".\n" << endl << endl;
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
		
		cout << "Enter number: ";
		cin >> option;

		

		guess = false;
		checkStar = false;
		
        //if the user chooses to enter a letter
		if (option == 1) 
		{
			cout << "\nEnter a letter: ";
			cin >> letterGuess;

			for (size_t i = 0; i < wordLen; i++)
			{
				if (letterGuess == wordToBeGuessed[i])
				{
					guess = true;
					//add letter to word
					wordNow[i] = letterGuess; 
				}
			}

			if (guess == true)
			{
				for (size_t i = 0; i < wordLen; i++)
				{
					if (wordNow[i].compare(asterisk) == 0)
					{
						checkStar = true;
					}
				}

				if (checkStar == true)
				{
					cout << endl << "\nCorrect!" << endl << endl;
				}
				else
				{
					//prettyYouWinText();
					system("CLS");
					youWin();
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
				cout << endl << "\nNope :(" << endl << endl;
			}
		}
        //if the user chooses to try to guess the whole word
		else if (option == 2) 
		{
			cout << "\nEnter a word: ";
			cin >> wordGuess;

			if (wordGuess.compare(wordToBeGuessed) == 0)
			{
				guess = true;
			}

			if (guess == true)
			{
				//prettyYouWinText();
				system("CLS");
				youWin();
				system("pause");
				system("CLS");
				Menu();
				return 0;
			}
			else
			{
				hang++;
				cout << endl << "\nNope :(" << endl << endl;
			}
		}
        //joker
		else if (option == 3) 
		{
			jokerCount++;

			if (jokerCount > (wordLen / 3))
			{
				cout << endl << "You've used all your jokers!" << endl;
			}
			else
			{
				for (size_t i = 0; i < wordLen; i++)
				{
					if (wordNow[i].compare(asterisk) == 0)
					{
						wordNow[i] = wordToBeGuessed[i];
						jokerLetter = wordToBeGuessed[i];
						break;
					}
				}

				for (size_t i = 0; i < wordLen; i++)
				{
					if (wordNow[i].compare(asterisk) == 0 && wordToBeGuessed[i] == jokerLetter)
					{
						wordNow[i] = jokerLetter;
					}
				}
			}
			
		}

		cout << endl;
		system("pause");
		//clear screen
		system("CLS"); 
	}
}