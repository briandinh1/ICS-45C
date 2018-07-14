// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>
#include <math.h>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
public:
	Triangle(int side1, int side2, int side3,
		string newName, string newColor, int newid)
		: Shape(newName, newColor, newid),
		side1(side1), side2(side2), side3(side3) {}

	virtual double area()
	{
		// Heron's formula for a triangle with 3 sides
		double s = (side1 + side2 + side3) / 2.0;
		return sqrt(s*(s - side1)*(s - side2)*(s - side3));
	}

	virtual void draw()
	{
		cout << color << ' ' << name << ' ' << id;
		int longest = getLongestSide();

		// triangle and circle are not to scale
		for (int i = 0; i <= longest; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				cout << '*';
			}
			cout << endl;
		}
	}

protected:
	int side1, side2, side3;

	int getLongestSide()
	{
		int longest = side1;
		if (side2 > longest) longest = side2;
		if (side3 > longest) longest = side3;
		return longest;
	}
};

#endif