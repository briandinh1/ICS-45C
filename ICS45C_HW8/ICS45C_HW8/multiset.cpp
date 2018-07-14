#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int myain()
{
	typedef istream_iterator<int> intit;

	ifstream rand("rand_numbers.txt");
	ofstream odd("odd_dinhb1.txt");
	ofstream even("even_dinhb1.txt");

	multiset<int> m;

	copy(intit(rand), intit(), inserter(m, m.begin()));

	for_each(m.begin(), m.end(),
		[&](const int & num)
	{ ((num % 2 == 0) ? even : odd) << num << endl; });

	cout << "Results have been sent to txt files." << endl << endl;

	return 0;
}