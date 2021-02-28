#include <iostream>
#include <Windows.h>
#include "frontEnd.h"
#include "hangman.h"
#include "wordFinding.h"

using namespace std;

//Rules
void rules() {
	cout << "|------------------------------------------------------------------------------------|" << endl;
	cout << "|                              _   _  _  _     __   __                               |" << endl;
	cout << "|                             |_)  |  |  |    |__  |__                               |" << endl;
	cout << "|                             | \\  |__|  |__  |__   __|                              |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|------------------------------------------------------------------------------------|" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|            --Hangman Game--             ||           --Find The Words--            |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|  1. You must choose one person in the   ||  1. In the console will be displayed    |" << endl;
	cout << "|  group who will be the host.            ||  a matrix filled with letters.          |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|  2. The host has to think of a secret   ||  2. Between these letters there is a    |" << endl;
	cout << "|  word and write it in the console.      ||  hidden word which you have to find.    |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|  3. The players should start guessing   ||  3. You will be given the length of the |" << endl;
	cout << "|  what the word is by choosing to guess  ||  hidden word and you will have to write |" << endl;
	cout << "|  the whole word or just a letter that   ||  in the console the word that you have  |" << endl;
	cout << "|  may be included in it(the word).       ||  found.                                 |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|  4. If the players guess correctly, the ||  4. The matrix will be displayed three  |" << endl;
	cout << "|  blanks will be filled with the correct ||  times with different hidden word       |" << endl;
	cout << "|  letters.                               ||  between different letters.             |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|  5. The players have 8 chances of       ||  5. If the players guess correctly two  |" << endl;
	cout << "|  guessing and in the 9th incorrect      ||  times they win the game otherwise      |" << endl;
	cout << "|  attempt they lose the game.            ||  they lose.                             |" << endl;
	cout << "|                                         ||                                         |" << endl;
	cout << "|------------------------------------------------------------------------------------|" << endl;
}

//print the HangingMan figure
void hangingMan(int hang)
{
	if (hang == 0) {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	else if (hang == 1)
	{
		cout << "_" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 2)
	{
		cout << "__________________" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 3)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 4)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 5)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 6)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|       /|" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 7)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 8)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|       /" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (hang == 9)
	{
		cout << "__________________" << endl;
		cout << "|        |" << endl;
		cout << "|        |" << endl;
		cout << "|        O" << endl;
		cout << "|       /|\\" << endl;
		cout << "|        |" << endl;
		cout << "|       / \\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	cout << endl;
}

//in Game Menu
void hangmanMenu()
{
	cout << "\n1.Guess a letter" << endl;
	cout << "2.Guess the whole word" << endl;
	cout << "3.Joker" << endl << endl;
}

void youWin() 
{
	cout << "\n|----------------------------------------------|" << endl;
	cout << "|   _  _   __   _  _     _       _  _   _  _   |" << endl;
	cout << "|    \\/   |  |  |  |      \\  ^  /   |   |\\ |   |" << endl;
	cout << "|    /    |__|  |__|       \\/ \\/    |   | \\|   |" << endl;
	cout << "|                                              |" << endl;
	cout << "|----------------------------------------------|\n" << endl;
}

void youLose() 
{
	cout << "\n|------------------------------------------------|" << endl;
	cout << "|    _  _   __   _  _     _     __    __    __   |" << endl;
	cout << "|     \\/   |  |  |  |     |    |  |  |__   |__   |" << endl;
	cout << "|     /    |__|  |__|     |__  |__|   __|  |__   |" << endl;
	cout << "|                                                |" << endl;
	cout << "|------------------------------------------------|\n" << endl;
}

//Main Menu
int Menu() 
{
	int numberChoice;
	cout << "|---------------------------|" << endl;
	cout << "|   _  _   __  _  _  _  _   |" << endl;
	cout << "|   |\\/|  |__  |\\ |  |  |   |" << endl;
	cout << "|   |  |  |__  | \\|  |__|   |" << endl;
	cout << "|                           |" << endl;
	cout << "|       1. Hangman          |" << endl;
	cout << "|       2. Find the words   |" << endl;
	cout << "|       3. Rules            |" << endl;
	cout << "|       4. Exit             |" << endl;
	cout << "|                           |" << endl;
	cout << "|---------------------------|" << endl;
	cout << "\n   Enter choice(number): " ;
	cin >> numberChoice;

	//HangMan
	if (numberChoice == 1) {
		system("CLS");
		hangman();
		cout << endl;
		system("pause");
		system("CLS"); 
		Menu();
	}

	//word finding game
	else if (numberChoice == 2) {
		system("CLS");
		wordFinding();
		cout << endl;
		system("pause");
		system("CLS"); 
		Menu();
	}

	//rules
	else if (numberChoice == 3) {
		system("CLS");
		rules();
		cout << endl;
		system("pause");
		system("CLS"); 
		Menu();
	}
	
	//exit
	else if (numberChoice == 4) {
		return 0;
	}
}