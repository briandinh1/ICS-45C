// ===================================================================
// Brian Dinh
// ID: 34546266
// ICS 45C HW1
// ===================================================================

#define STACK_CAPACITY 1000

#include <iostream>
#include <string>

using namespace std;

double milesPerMinute(int knot);

class Stack
{
public:
	Stack() : currentPosition(-1){}

	// ---------------------------------------------------------------

	void push(char c)
	{
		if (isFull())
		{
			stack_error("Full stack");
			return;
		}

		stack[++currentPosition] = c;
	}

	// ---------------------------------------------------------------

	void pop()
	{
		if (isEmpty()) stack_error("Empty stack");

		--currentPosition;
	}

	// ---------------------------------------------------------------

	char top()
	{
		if (isEmpty())
		{
			stack_error("No elements");
			return NULL;
		}

		return stack[currentPosition];
	}

	// ---------------------------------------------------------------

	bool isEmpty()
	{
		return currentPosition <= -1;
	}

	// ---------------------------------------------------------------

	~Stack(){} // destructor not used

private:
	char stack[STACK_CAPACITY];
	int currentPosition;

	// ---------------------------------------------------------------

	bool isFull()
	{
		return currentPosition >= STACK_CAPACITY - 1;
	}

	// ---------------------------------------------------------------

	void stack_error(string errorMessage)
	{
		cout << errorMessage << endl;
	}
};

// ===================================================================

int main(int argc, char *argv[])
{
	cout << "Hello World!\n"; // copy pasted as directed

	// ---------------------------------------------------------------

	int knot;
	cout << "Enter knot(s):  ";
	cin >> knot;

	cout << milesPerMinute(knot) << endl;

	// ---------------------------------------------------------------

	string myString;
	cout << "Enter a string:  ";
	cin.ignore();
	getline(cin,myString);

	if (!cin.eof()) // check for ^Z
	{
		Stack reverseString;

		// push characters of myString onto stack
		for (size_t i = 0; i < myString.size(); ++i)
		{
			reverseString.push(myString[i]);
		}

		// display in reverse, remove from stack 
		for (size_t i = 0; i < myString.size(); ++i)
		{
			cout << reverseString.top();
			reverseString.pop();
		}
	}

	return 0;
}

double milesPerMinute(int knot)
{
	double fphRatio = 6076.0 / 5280.0; // ratio between nautical fph and fph
	double mph = knot * fphRatio; //converting from knots to miles per hour
	return (mph / 60); // converting from miles per hour to miles per minute;
}