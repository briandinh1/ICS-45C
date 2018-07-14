// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_6
// =========================================================

#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;

class Picture
{
public:
	Picture(Shape * s = nullptr, Picture * p = nullptr)
		: shape(s), next(p), head(nullptr) {}

	void addShape(Shape* s)
	{
		Picture * temp = new Picture(s, head);
		head = temp;
	}

	void drawAll()
	{
		Picture * temp = head;
		while (temp)
		{
			temp->shape->draw();
			temp = temp->next;
			cout << endl;
		}
	}

	double totalArea()
	{
		double total = 0.0;
		Picture * temp = head;
		while (temp)
		{
			total += temp->shape->area();
			temp = temp->next;
		}

		return total;
	}

	~Picture()
	{
		Picture * lead = head;
		Picture * follow;

		while (lead)
		{
			follow = lead;
			lead = lead->next;
			delete follow->shape;
			delete follow;
		}
	}

private:
	Shape * shape;
	Picture * next; 
	Picture * head;
};

#endif