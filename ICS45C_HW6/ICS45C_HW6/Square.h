// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;

class Square : public Shape
{
public:
	Square(int newSide, string newName, string newColor, int newid) 
		: Shape(newName, newColor, newid), side(newSide) {}

	virtual double area()
	{
		return side * side;
	}

	virtual void draw()
	{
		cout << color << ' ' << name << ' ' << id << endl;

		for (int i = 0; i < side; ++i)
		{
			for (int j = 0; j < side; ++j)
			{
				cout << '*';
			}
			cout << endl;
		}
	}

protected:
	int side;
};

#endif