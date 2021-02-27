#include <iostream>
#include <Windows.h>
#include "frontEnd.h"
#include "hangman.h"
#include "wordFinding.h"
using namespace std;

void rules() {
	cout << "|-----------------------------------------|" << endl;
	cout << "|         _   _  _  _     __   __         |" << endl;
	cout << "|        |_)  |  |  |    |__  |__         |" << endl;
	cout << "|        | \\  |__|  |__  |__   __|        |" << endl;
	cout << "|                                         |" << endl;
	cout << "|                                         |" << endl;
	cout << "|       --Rules for Hangman Game--        |" << endl;
	cout << "|                                         |" << endl;
	cout << "|   1. You must choose one person in the  |" << endl;
	cout << "|   group who will be the host.           |" << endl;
	cout << "|   2. The host has to think of a secret  |" << endl;
	cout << "|   word and write it in the console.     |" << endl;
	cout << "|   3. The players should start guessing  |" << endl;
	cout << "|   what the word is by choosing to guess |" << endl;
	cout << "|   the whole word or just a letter that  |" << endl;
	cout << "|   may be included in it(the word).      |" << endl;
	cout << "|   4. If the players guess correctly,    |" << endl;
	cout << "|   the blanks will be filled with the    |" << endl;
	cout << "|   correct letters.                      |" << endl;
	cout << "|   5. The players have 8 chances of      |" << endl;
	cout << "|   guessing and in the 9th incorrect     |" << endl;
	cout << "|   attempt they lose the game.           |" << endl;
	cout << "|                                         |" << endl;
	cout << "|-----------------------------------------|" << endl;
}

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
	}//etc.
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

void hangmanMenu()
{
	cout << endl;
	cout << "1.Guess a letter" << endl;
	cout << "2.Guess the whole word" << endl;
	cout << "3.Joker" << endl << endl;
}

int Menu() {
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
	if (numberChoice == 1) {
		system("CLS");
		hangman();
		system("pause");
		//clear screen
		system("CLS"); 
		Menu();
	}
	else if (numberChoice == 2) {
		system("CLS");
		wordFinding();
		system("pause");
		//clear screen
		system("CLS"); 
		Menu();
	}
	else if (numberChoice == 3) {
		system("CLS");
		rules();
		system("pause");
		//clear screen
		system("CLS"); 
		Menu();
	}
	else if (numberChoice == 4) {
		return 0;
	}
}