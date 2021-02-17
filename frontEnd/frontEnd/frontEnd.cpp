#include <iostream>
#include "rules.h"
using namespace std;

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

	}
	else if (numberChoice == 2) {

	}
	else if (numberChoice == 3) {

	}
	else if (numberChoice == 4) {
		rules();
	}
	else if (numberChoice == 5) {
		return 0;
	}
}

int main()
{
	Menu();
}