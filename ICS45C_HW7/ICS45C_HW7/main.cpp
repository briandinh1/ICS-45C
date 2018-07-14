// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_7
// =========================================================

#include <iostream>
#include <string>
#include "Array.h"
#include "Matrix.h"
#include "Exception.h"

using namespace std;

template <class T>
void fillMatrix(Matrix <T> & m)
{
	int i, j;

	// fixed this provided code
	/*for (i = 0; i < m.numRows(); i++)
		m[i][0] = T();
		for (j = 0; j < m.numCols(); j++)
		m[0][j] = T();*/

	for (i = 0; i < m.numRows(); ++i)
		for (j = 0; j < m.numCols(); ++j)
			m[i][j] = T();

	for (i = 1; i < m.numRows(); ++i)
		for (j = 1; j < m.numCols(); ++j)
			m[i][j] = T(i * j);
}

int main()
{
	Matrix<int> m(10, 5);
	fillMatrix(m);
	cout << m;

	cout << endl << endl;

	Matrix<double> M(8, 10);
	fillMatrix(M);
	cout << M;

	cout << endl << endl;

	// testing matrix's index out of bounds
	try
	{
		cout << m[2000][1] << endl;
	}
	catch (IndexOutOfBoundsException)
	{
		cout << "Index out of bounds!" << endl << endl;
	}

	// testing array's index out of bounds
	try
	{
		cout << m[1][2000] << endl;
	}
	catch (IndexOutOfBoundsException)
	{
		cout << "Index out of bounds!" << endl << endl;
	}
	

	return 0;
}