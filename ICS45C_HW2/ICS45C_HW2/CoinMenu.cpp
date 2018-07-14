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

void evaluateCoins(Coins & myCoins);
int getAnswer();
void displayMenu();
Coins deposit();
int extract();

int main()
{
	// part 3 of HW2
	Coins myCoins;
	evaluateCoins(myCoins);

	return 0;
}

void evaluateCoins(Coins & myCoins)
{
	while (int answer = getAnswer())
	{
		cout << endl;

		switch (answer)
		{
		case 1:
		{
			myCoins.depositChange(deposit());
			cout << "Deposit operation complete" << endl << endl;
			break;
		}
		case 2:
		{
			Coins moneyPit = myCoins.extractChange(extract());
			cout << "Extraction operation complete" << endl << endl;
			break;
		}
		case 3:
		{
			cout << "You have " << myCoins << endl << endl;
			break;
		}
		case 4: return;
		default: return; // something went wrong if it defaulted 
		}
	}
}

int getAnswer()
{
	int answer;

	while (true)
	{
		displayMenu();

		cin >> answer;

		if (answer >= 1 && answer <= 4) return answer;

		cout << endl << "Please choose 1, 2, 3, or 4 only " << endl << endl;
	}
}

void displayMenu()
{
	cout << "(1) Deposit change" << endl
		<< "(2) Extract change" << endl
		<< "(3) View balance" << endl
		<< "(4) Exit the program" << endl
		<< "Enter a number:  ";
}

Coins deposit()
{
	int q, d, n, p;

	cout << "How many quarters?  ";
	cin >> q;
	cout << "How many dimes?  ";
	cin >> d;
	cout << "How many nickels?  ";
	cin >> n;
	cout << "How many pennies?  ";
	cin >> p;

	return Coins(q, d, n, p);
}

int extract()
{
	int amount;
	cout << "How many cents do you want to take out?  ";
	cin >> amount;
	return amount;
}