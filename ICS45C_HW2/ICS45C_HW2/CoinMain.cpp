// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_2
// =========================================================

#include <iostream>
#include <string>
#include "Coins.h"

using namespace std;

const int CENTS_FOR_CANDYBAR = 482;
const int CENTS_FOR_CHIPS = 68;

void pauseScreen(string prompt); // for readability on the terminal

int main()
{
	/*
	// part 1 of HW2: given, example code 
	{
	Coins pocket(100, 10, 10, 100);
	cout << "I started with " << pocket << " in my pocket" << endl;

	Coins payForCandy = pocket.extractChange(CENTS_FOR_CANDYBAR);
	cout << "I bought a candy bar for " << CENTS_FOR_CANDYBAR
	<< " cents using " << payForCandy << endl;

	cout << "I have " << pocket << " left in my pocket" << endl << endl;
	}
	*/

	// --------------------------------------------------------
	// part 2 of HW2

	Coins pocket(5, 3, 6, 8);
	Coins piggyBank(50, 50, 50, 50);

	// buying chips
	cout << "Pocket contains " << pocket << endl;

	Coins payForChips = pocket.extractChange(CENTS_FOR_CHIPS);
	cout << "You buy a bag of chips for " << payForChips << endl;

	cout << "Pocket now contains " << pocket << endl;

	pauseScreen("\nPress ENTER to continue...");
	cout << endl << endl;

	// transferring from piggy bank
	cout << "Piggy bank contains " << piggyBank << endl;

	Coins transfer = piggyBank.extractChange(187); // amount chosen arbitrarily 
	cout << "You want to transfer " << transfer
		<< "from your piggy bank to your pocket" << endl << endl;

	pocket.depositChange(transfer);
	cout << "Pocket now contains " << pocket << endl;
	cout << "Piggy bank now contains " << piggyBank << endl;

	pauseScreen("\nPress ENTER to continue...");
	cout << endl << endl;

	// vacuuming, finding loose change
	cout << "While vacuuming, you find loose change in the sofa " << endl
		<< "You deposit it in your piggy bank" << endl << endl;

	Coins looseChange(3, 2, 1, 0); // coins chosen arbitrarily
	piggyBank.depositChange(looseChange);

	cout << "Piggy bank now contains " << piggyBank << endl;
}

void pauseScreen(string prompt)
{
	cout << prompt;
	cin.ignore(99, '\n');
}