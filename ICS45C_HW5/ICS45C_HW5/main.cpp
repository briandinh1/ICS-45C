// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_5
// =========================================================

#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();

	cout << "+: " << firstString + secondString << endl;
	cout << "+=: " << (firstString += secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;
	cout << "LT: " << (secondString < firstString) << endl;
	cout << "<<: " << fifthString << endl;
	cout << "<<: " << fourthString << endl;
	cout << "==: " << (fifthString == fourthString) << endl;
	cout << "[]: " << thirdString[1] << endl;
	fifthString = thirdString;
	cout << "<<: " << fifthString << " " << thirdString << endl;
	cout << "[]: " << fifthString[1] << endl;
	cout << "[]: " << fifthString[10] << endl;

	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;

	cout << (firstString < secondString) << endl;
	cout << (firstString == thirdString) << endl;

	return 0;
}
