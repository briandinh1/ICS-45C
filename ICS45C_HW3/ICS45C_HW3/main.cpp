// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_3
// =========================================================

#include <iostream>
#include "String.h"

using namespace std;

void tester();
void pauseScreen(String prompt);

int main()
{
	//tester();

	return 0;
}

void tester()
{
	// default construction:
	String blank;
	cout << blank << endl; // should show nothing

	// construction with string literal:
	String str1("String #1");
	cout << str1 << " created" << endl;

	// copy construction:
	String str2(str1);
	cout << "Copied " << str2 << endl;

	pauseScreen("Press ENTER to continue...");
	// ---------------------------------------------------------------

	// using operator = with a string literal
	str1 = "New String #1";
	cout << str1 << endl;

	// using operator = with another String object
	str2 = str1;
	cout << "Copied " << str2 << endl;

	pauseScreen("Press ENTER to continue...");
	// ---------------------------------------------------------------

	// getting the size
	int size = str1.size();
	cout << str1 << "'s size is " << size << endl << endl;

	// using operator[] within bounds
	for (int i = 0; i < size; ++i)
		cout << "Index " << i << " is:\t" << str1[i] << endl; 

	// using operator[] out of bounds
	cout << endl<< "Index 9000 is: ";
	cout << str1[9000] << endl;

	pauseScreen("Press ENTER to continue...");
	// ---------------------------------------------------------------

	String zero = "0";
	String one = "1";
	String nineThousand = "9000"; // should not ever print after operations

	cout << "The variables are: "
		<< zero << ", " << one << ", " << nineThousand << endl << endl;

	// using operator +
	cout << "Original nineThousand: " << nineThousand << endl;

	nineThousand = zero + one;

	cout << "Unchanged zero: " << zero << endl
		<< "Unchanged one: " << one << endl
		<< "Modified nineThousand: " << nineThousand << " after zero + one" << endl << endl;

	// using operator +=
	zero += nineThousand;
	cout << "Unchanged nineThousand: " << nineThousand << endl
		<< "Modified zero: " << zero << " after zero+=nineThousand" << endl;

	pauseScreen("Press ENTER to continue...");
	// ---------------------------------------------------------------

	// finding out the reverse of a string
	String forward("stressed");
	cout << "The forward word is:  " << forward << endl;

	String reverse = forward.reverse();
	cout << "The reverse word is:  " << reverse << endl << endl;

	// finding the index of a single character
	int index = forward.indexOf('e'); // should give 3 for the first 'e'
	cout << "First occurence of 'e' is at index " << index << endl;

	// finding the index of a pattern that exists
	index = forward.indexOf("esse"); // should still give 3
	cout << "First occurence of \"esse\" is at index " << index << endl;

	// finding the index of a pattern that does not exist, returns -1
	String doesNotExist = "c++";
	index = forward.indexOf(doesNotExist);
	cout << "First occurence of " << doesNotExist << " is " << index
		<< " because it does not exist in the string" << endl;

	pauseScreen("Press ENTER to continue...");
	// ---------------------------------------------------------------

	cout << "Comparison test" << endl
		<< "Returns boolean 1 for true, 0 for false" << endl << endl;

	String compare1;
	String compare2;

	// reading in values
	cout << "Choose a starting word: ";
	cin >> compare1;

	cout << "Choose a word to compare to " << compare1 << ":  ";
	cin >> compare2;

	cout << endl;

	// using operator ==
	cout << compare1 << " == " << compare2 << "?\t" << (compare1 == compare2) << endl;

	// using operator !=
	cout << compare1 << " != " << compare2 << "?\t" << (compare1 != compare2) << endl;

	// using operator >
	cout << compare1 << " > " << compare2 << "?\t" << (compare1 > compare2) << endl;

	// using operator <
	cout << compare1 << " < " << compare2 << "?\t" << (compare1 < compare2) << endl;

	// using operator >=
	cout << compare1 << " >= " << compare2 << "?\t" << (compare1 >= compare2) << endl;

	// using operator <=
	cout << compare1 << " <= " << compare2 << "?\t" << (compare1 <= compare2) << endl;

	// ---------------------------------------------------------------
	cout << endl << endl;
}

void pauseScreen(String prompt)
{
	cout << endl << prompt << endl;
	cin.ignore(99, '\n');
}