// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape
{
public:
	Shape() {}
	Shape(string newName, string newColor, int newid) 
		: name(newName), color(newColor), id(newid) {}

	string name, color;
	int id;

	virtual double area() = 0;
	virtual void draw() = 0;

	~Shape() {}
};

#endif