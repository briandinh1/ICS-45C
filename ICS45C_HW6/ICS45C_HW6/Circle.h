// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
public:
	Circle(int radius, string newName, string newColor, int newid)
		: Shape (newName, newColor, newid), radius(radius) {}

	virtual double area()
	{
		const double PI = 3.1415926535897;
		return PI*radius*radius;
	}

	virtual void draw()
	{
		cout << color << ' ' << name << ' ' << id << endl;

		// circle and triangle are not to scale
		cout << "   ***  " << endl;
		cout << " ******* " << endl;
		cout << "*********" << endl;
		cout << "*********" << endl;
		cout << "*********" << endl;
		cout << " ******* " << endl;
		cout << "   ***   " << endl;
	}

protected:
	int radius;
};

#endif