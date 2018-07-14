// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_5
// =========================================================

#include <iostream>
#include <fstream>

using namespace std;

class String
{
public:
	String(const char * s = "") : head(ListNode::stringToList(s)) {}

	String(const String & s) : head(ListNode::copy(s.head)) {}

	String operator = (const String & s)
	{
		ListNode::deleteList(*this);
		head = ListNode::copy(s.head);
		return *this;
	}

	char & operator [] (const int index)
	{
		if (!inBounds(index))
		{
			static char nullchar = '\0';
			cout << "Index " << index << " out of bounds!" << endl;
			return nullchar;
		}

		ListNode *temp = head;
		for (int i = 0; i < index; ++i) temp = temp->next;
		return temp->info;

	}

	int length() const
	{
		return ListNode::length(head);
	}

	int indexOf(char c) const
	{
		ListNode *temp = head;
		for (int i = 0; temp; ++i)
		{
			if (temp->info == c) return i;
			temp = temp->next;
		}

		return -1;
	}

	bool operator == (const String & s) const
	{
		return ListNode::equal(head, s.head);
	}

	bool operator < (const String & s) const
	{
		return ListNode::compare(head, s.head) <= -1 ? true : false;
	}

	String operator + (const String & s) const
	{
		ListNode * temp = ListNode::concat(head, s.head);
		String newString;
		newString.head = temp;
		return newString;
	}

	String operator += (const String & s)
	{
		return operator = (operator + (s));
	}

	void print(ostream & out)
	{
		ListNode * temp = head;
		while (temp)
		{
			out << temp->info;
			temp = temp->next;
		}
	}

	void read(istream & in)
	{
		char temp[100000];
		in.getline(temp,100000);
		ListNode::deleteList(*this);
		head = ListNode::stringToList(temp);
	}

	~String()
	{
		ListNode::deleteList(*this);
	}

private:
	bool inBounds(int i)
	{
		return i >= 0 && i < ListNode::length(head);
	}

	struct ListNode
	{
		char info;
		ListNode * next;

		ListNode(char newInfo, ListNode * newNext) : info(newInfo), next(newNext) {}

		static ListNode * stringToList(const char *s)
		{
			char * temp = new char[strlen(s) + 1];
			reverse(temp, s);

			ListNode * head = new ListNode(*temp, nullptr);
			ListNode * next = head;

			for (int i = 1; s[i] != '\0'; ++i)
				next = head = new ListNode(temp[i], next);

			delete[] temp;

			return head;
		}

		static ListNode * copy(ListNode * L)
		{
			return !L ? nullptr : new ListNode(L->info, copy(L->next));
		}

		static bool equal(ListNode * L1, ListNode * L2)
		{
			return !L1 || !L2
				? L1 == L2
				: L1->info == L2->info && equal(L1->next, L2->next);
		}

		static ListNode * concat(ListNode * L1, ListNode * L2)
		{
			return !L1
				? copy(L2)
				: new ListNode(L1->info, concat(L1->next, L2));
		}

		static int compare(ListNode * L1, ListNode * L2)
		{
			while (L1 && L2 && L1->info == L2->info)
			{
				L1 = L1->next;
				L2 = L2->next;
			}

			if (L1 && L2) return (L1->info > L2->info) ? 1 : -1;
			else if (L1 && !L2) return 1;
			else if (!L1 && L2) return -1;

			return 0;
		}

		static int length(ListNode * L)
		{
			return !L ? 0 : 1 + length(L->next);
		}

		static char* reverse(char * c, const char * s)
		{
			int last = strlen(s) - 1;

			for (int i = 0; s[i] != '\0'; ++i)
				c[i] = s[last - i];

			c[strlen(s)] = '\0';

			return c;
		}

		static int strlen(const char *s)
		{
			int i = 0;
			while (*s++ != '\0') ++i;
			return i;
		}

		static void deleteList(String & s)
		{
			ListNode * lead = s.head;
			ListNode * follow;

			while (lead)
			{
				follow = lead;
				lead = lead->next;
				delete follow;
			}
		}
	};

	ListNode * head;
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
