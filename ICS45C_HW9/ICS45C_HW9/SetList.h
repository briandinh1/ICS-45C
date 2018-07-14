// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_9
// =========================================================

#ifndef SETLIST_H
#define SETLIST_H

#include <iostream>

using namespace std;

template <typename T>
class SetList
{
public:
	struct ListNode
	{
		T info;
		ListNode * next;

		ListNode(T newInfo, ListNode * newNext) : info(newInfo), next(newNext) {}

		static void deleteList(SetList & s)
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

	// ================================================================

	struct iterator
	{
		// Iterator traits
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T value_type;
		typedef ListNode& reference;
		typedef ListNode* pointer;
		typedef ptrdiff_t difference_type;

	private:
		pointer buf;

	public:
		iterator(pointer ptr = nullptr) : buf(ptr) { }
		self_type operator++() { buf = buf->next; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf = buf->next; return cpy; }
		reference operator*() { return *buf; }
		pointer operator->() { return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};

	// ================================================================

	SetList() : head(nullptr) {}

	void insert(const T& val)
	{
		ListNode * start = new ListNode(val, head);
		head = start;
	}

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(); }

	iterator find(const T& val)
	{
		ListNode * temp = head;
		while (temp)
		{
			if (temp->info == val) return iterator(temp);
			temp = temp->next;
		}

		return end();
	}

	~SetList()
	{
		ListNode::deleteList(*this);
	}

private:
	ListNode * head;
};


#endif