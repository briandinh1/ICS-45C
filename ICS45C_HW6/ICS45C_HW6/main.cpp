// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#include <iostream>
#include <string>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Picture.h"

using namespace std;

void pauseScreen(string prompt);

int main()
{
	Picture p;
	p.addShape(new Triangle(5, 5, 5, "Triangle", "Green", 86));
	p.addShape(new Triangle(4, 3, 5, "Triangle", "Red", 240));
	p.addShape(new Circle(5, "Circle", "Yellow", 2000));
	p.addShape(new Circle(10, "Circle", "Purple", 675));
	p.addShape(new Square (5, "Square", "Blue", 34));
	p.addShape(new Square(10, "Square", "Orange", 458));
	p.addShape(new Rectangle(4, 8, "Rectangle", "White", 7));
	p.addShape(new Rectangle(8, 4, "Rectangle", "Black", 15));

	cout << "Total area is: " << p.totalArea() << endl << endl;
	pauseScreen("Press ENTER to see the shapes");

	cout << endl << "Shapes are: " << endl << endl;
	p.drawAll();

	return 0;
}

void pauseScreen(string prompt)
{
	cout << prompt;
	cin.ignore(99, '\n');
}