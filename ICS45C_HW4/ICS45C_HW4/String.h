// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_4
// =========================================================

#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

class String
{
public:
	// ---------------------------------------------------------------
	// CONSTRUCTORS:

	String(const char * s = "") : buf(strdup(s)) {}

	String(const String & s) : buf(strdup(s.buf)) {}

	// ---------------------------------------------------------------
	// OPERATORS:

	String operator = (const String & s)
	{
		delete[] buf;
		buf = strdup(s.buf);
		return *this;
	}

	char & operator [] (int index)
	{
		if (!inBounds(index))
		{
			cout << "Index " << index << " is out of bounds!" << endl;
			return buf[size()];
		}
		return buf[index];
	}

	bool operator == (const String s)
	{
		return (strcmp(buf, s.buf) == 0) ? true : false;
	}

	bool operator != (const String s)
	{
		return !operator == (s);
	}

	bool operator > (const String s)
	{
		return (strcmp(buf, s.buf) >= 1) ? true : false;
	}

	bool operator < (const String s)
	{
		return (strcmp(buf, s.buf) <= -1) ? true : false;
	}

	bool operator <= (const String s)
	{
		return operator <(s) || operator == (s);
	}

	bool operator >= (const String s)
	{
		return operator >(s) || operator == (s);
	}

	String operator + (const String s)
	{
		int len = strlen(buf) + strlen(s.buf);
		char*temp = new char[len + 1];

		int i;
		for (i = 0; buf[i] != '\0'; ++i)
			temp[i] = buf[i];

		for (int j = 0; s.buf[j] != '\0'; ++j)
			temp[i++] = s.buf[j];

		temp[len] = '\0';

		String newString(temp);
		delete[] temp;

		return newString;
	}

	String operator += (const String s)
	{
		return operator = (operator +(s));
	}


	// ---------------------------------------------------------------
	// METHODS:

	int size()
	{
		return strlen(buf);
	}

	String reverse()
	{
		int len = strlen(buf);
		char * temp = new char[len + 1];
		for (int i = len; i > 0; --i) temp[len - i] = buf[i - 1];
		temp[len] = '\0';
		String reverse(temp);
		delete[] temp;
		return reverse;
	}

	int indexOf(const char c)
	{
		for (int i = 0; buf[i] != '\0'; ++i)
			if (buf[i] == c) return i;

		return -1;
	}

	int indexOf(const String pattern)
	{
		int counter;
		int patternLen = strlen(pattern.buf);
		int limit = strlen(buf) - patternLen;

		for (int i = 0; i <= limit; ++i)
		{
			counter = 0;

			for (int j = 0; j < patternLen; ++j)
			{
				if (buf[i + j] == pattern.buf[j]) ++counter;
				if (counter == patternLen) return i;
			}
		}

		return -1;
	}

	void print(ostream & out)
	{
		out << buf;
	}

	void read(istream & in)
	{
		in >> buf;
	}

	// ---------------------------------------------------------------
	// DESTRUCTOR:

	~String()
	{
		delete[] buf;
	}

private:
	bool inBounds(int i)
	{
		return i >= 0 && i < strlen(buf);
	}

	static int strlen(const char *s)
	{
		int i=0;
		while (*s++ != '\0') ++i;
		return i;
	}

	static char *strcpy(char *dest, const char *src)
	{
		if (dest == nullptr) return nullptr;

		int i;
		for (i = 0; src[i] != '\0'; ++i) dest[i] = src[i];
		dest[i] = '\0';

		return dest;
	}

	static char *strdup(const char *src)
	{
		char * newString = new char[strlen(src) + 1];
		return strcpy(newString, src);
	}

	static int strcmp(const char *left, const char *right)
	{
		int i;

		for (i = 0; left[i] && right[i]; ++i)
			if (left[i] != right[i]) break;

		if (left[i] == right[i]) return 0;

		return (left[i] > right[i]) ? 1 : -1;
	}

	char * buf;
};

ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}

istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
