#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "frontEnd.h"
#include "hangman.h"
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

int Menu() {
	int numberChoice;
	cout << "|---------------------------|" << endl;
	cout << "|   _  _   __  _  _  _  _   |" << endl;
	cout << "|   |\\/|  |__  |\\ |  |  |   |" << endl;
	cout << "|   |  |  |__  | \\|  |__|   |" << endl;
	cout << "|                           |" << endl;
	cout << "|       1. Hangman          |" << endl;
	cout << "|       2. Crossword        |" << endl;
	cout << "|       3. Find the words   |" << endl;
	cout << "|       4. Rules            |" << endl;
	cout << "|       5. Exit             |" << endl;
	cout << "|                           |" << endl;
	cout << "|---------------------------|" << endl;
	cout << "\n   Enter choice(number): " ;
	cin >> numberChoice;
	if (numberChoice == 1) {
		system("CLS");
		hangman();
	}
	else if (numberChoice == 2) {

	}
	else if (numberChoice == 3) {

	}
	else if (numberChoice == 4) {
		system("CLS");
		rules();
		system("pause");
		system("CLS"); //clear screen
		Menu();
	}
	else if (numberChoice == 5) {
		return 0;
	}
}