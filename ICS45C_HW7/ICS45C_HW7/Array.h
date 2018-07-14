// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_7
// =========================================================

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Exception.h"

using namespace std;

template <typename T>
class Array
{
private:
	int len;
	T * buf;

public:
	Array(int newLen)
		: len(newLen), buf(new T[newLen]) {}

	Array(Array & l)
		: len(l.len), buf(new T[l.len])
	{
		for (int i = 0; i < l.len; ++i)
			buf[i] = l.buf[i];
	}

	int length()
	{
		return len;
	}

	T & operator [] (int i)
		throw (IndexOutOfBoundsException)
	{
		if (i < 0 || i > len)
			throw IndexOutOfBoundsException();
		return buf[i];
	}

	void print(ostream & out)
	{
		for (int i = 0; i < len; ++i)
			out << setw(5) << buf[i];
	}

	friend ostream & operator << (ostream & out, Array & a)
	{
		a.print(out);
		return out;
	}

	friend ostream & operator << (ostream & out, Array * ap)
	{
		ap->print(out);
		return out;
	}

	~Array()
	{
		delete[] buf;
	}
};

#endif