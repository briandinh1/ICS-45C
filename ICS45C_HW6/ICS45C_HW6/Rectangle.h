// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include "Square.h"

using namespace std;

class Rectangle : public Square
{
public:
	Rectangle(int newSide, int newWidth, 
		string newName, string newColor, int newid)
		: Square(newSide, newName, newColor, newid), width(newWidth) {}

	virtual double area()
	{
		return side * width;
	}

	virtual void draw()
	{
		cout << color << ' ' << name << ' ' << id << endl;

		for (int i = 0; i < side; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				cout << '*';
			}
			cout << endl;
		}
	}

protected:
	int width;
};

#endif