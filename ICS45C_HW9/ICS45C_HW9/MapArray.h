// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_9
// =========================================================

#ifndef MAPARRAY_H
#define MAPARRAY_H

#include <iostream>
#include <utility>

using namespace std;

template <typename T1, typename T2>
class MapArray
{
	pair<T1, T2>* buf;
	int size; // logical size
	int capacity; // physical size

	void sort()
	{
		int j;
		pair<T1, T2> temp;

		for (int i = 1; i < size; ++i)
		{
			j = i;

			while (j > 0 && buf[j].first < buf[j - 1].first)
			{
				temp = buf[j];
				buf[j] = buf[j - 1];
				buf[j - 1] = temp;
				--j;
			}
		}
	}

	// ================================================================

public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef pair<T1, T2> value_type;
		typedef pair<T1, T2>& reference;
		typedef pair<T1, T2>* pointer;
		typedef ptrdiff_t difference_type;

	private:
		pointer buf;

	public:
		iterator(pointer ptr = nullptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; ++buf; return cpy; }
		reference operator*() { return *buf; }
		pointer operator->() { return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};

	// ================================================================

	MapArray(int cap = 1000) : capacity(cap), size(0), buf(new pair<T1, T2>[cap]) {}

	void insert(T1 index)
	{
		for (int i = 0; i < size; ++i)
		{
			if (buf[i].first == index)
			{
				buf[i].second++;
				return;
			}
		}

		buf[size].first = index;
		buf[size++].second++;

		sort();
	}

	iterator begin() { return iterator(buf); }
	iterator end() { return iterator(buf + size); }

	~MapArray() { delete[] buf; }
};


#endif