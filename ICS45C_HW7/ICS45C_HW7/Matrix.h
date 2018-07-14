// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_7
// =========================================================

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Array.h"
#include "Exception.h"

using namespace std;

template <typename Element>
class Matrix
{
private:
	int rows, cols;
	Array<Array<Element>*> m;

public:
	Matrix(int newRows, int newCols)
		: rows(newRows), cols(newCols), m(rows)
	{
		for (int i = 0; i < rows; ++i)
			m[i] = new Array<Element>(cols);
	}

	int numRows()
	{
		return rows;
	}

	int numCols()
	{
		return cols;
	}

	Array <Element> & operator [] (int row)
		throw (IndexOutOfBoundsException)
	{
		if (row < 0 || row > rows)
			throw IndexOutOfBoundsException();
		return *m[row];
	}

	void print(ostream & out)
	{
		for (int i = 0; i < rows; ++i)
			cout << m[i] << endl;
	}

	friend ostream & operator << (ostream & out, Matrix & m)
	{
		m.print(out);
		return out;
	}
};

#endif