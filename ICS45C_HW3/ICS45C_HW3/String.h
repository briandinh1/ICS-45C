// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_3
// =========================================================

#include <iostream>
#include <fstream>

using namespace std;

#define MAXLEN 128
class String
{
public:
	// ---------------------------------------------------------------
	// CONSTRUCTORS:
	String(const char * s = "")
	{
		strcpy(buf, s);
	}

	String(const String & s)
	{
		strcpy(buf, s.buf);
	}

	// ---------------------------------------------------------------
	// OPERATORS:

	String operator = (const String & s)
	{
		strcpy(buf, s.buf);
		return *this;
	}

	char & operator [] (int index)
	{
		if (!inBounds(index))
		{
			cout << "Index out of Bounds!!!" << endl;
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
		return (strcmp(buf, s.buf) != 0) ? true : false;
	}

	bool operator > (const String s)
	{
		return (strcmp(buf, s.buf) >= 1) ? true : false;
	}

	bool operator < (const String s)
	{
		return (strcmp(buf, s.buf) <= -1) ? true : false;
	}

	bool operator >= (const String s)
	{
		return (strcmp(buf, s.buf) >= 0) ? true : false;
	}

	bool operator <= (const String s)
	{
		return (strcmp(buf, s.buf) <= 0) ? true : false;
	}

	String operator + (const String s)
	{
		char newString[MAXLEN];
		strcat(strcpy(newString, buf), s.buf);
		return newString;
	}

	String operator += (const String s)
	{
		strcat(buf, s.buf);
		return *this;
	}

	// ---------------------------------------------------------------
	// METHODS:
	int size()
	{
		return strlen(buf);
	}

	String reverse()
	{
		char reverse[MAXLEN];
		int len = strlen(buf);
		for (int i = len; i > 0; --i) reverse[len - i] = buf[i - 1];
		reverse[len] = '\0';
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
		// finds the first character of the pattern
		char * ptr = strchr(buf, *pattern.buf);
		int len = strlen(pattern.buf);

		// continues to do so if it doesn't reach the end of the string
		while (ptr != '\0')
		{
			for (int i = 0; i < len; ++i)
			{
				if (ptr[i] != pattern.buf[i]) break;
				if (i == len - 1) return (int)(ptr - buf);
			}

			++ptr = strchr(ptr, *pattern.buf);
		}

		// otherwise, not found
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

	~String(){}


private:
	bool inBounds(int i)
	{
		return i >= 0 && i < strlen(buf);
	}

	static int strlen(const char *s)
	{
		int i = 0;
		while (s[i] != '\0') ++i;
		return i;
	}

	static char *strcpy(char *dest, const char *src)
	{
		int i;
		for (i = 0; src[i] != '\0' && i < MAXLEN - 1; ++i) dest[i] = src[i];
		dest[i] = '\0';

		return dest;
	}

	static char *strcat(char *dest, const char *src)
	{
		strcpy(dest + strlen(dest), src);
		return dest;
	}

	static int strcmp(const char *left, const char *right)
	{
		int i;

		for (i = 0; left[i] && right[i]; ++i)
			if (left[i] != right[i]) break;

		if (left[i] == right[i]) return 0;

		return (left[i] > right[i]) ? 1 : -1;
	}

	static char *strchr(const char *str, int c)
	{
		while (*str != '\0')
		{
			++str;
			if (*str == c) return (char *)str;
		}

		return nullptr;
	}

	char buf[MAXLEN];
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
