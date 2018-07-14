#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
// =========================================================
// Brian Dinh
// dinhb1@uci.edu
// # 34546266
// ICS 45C HW_9
// =========================================================

#include "SetList.h"
#include "MapArray.h"

using namespace std;

int main()
{
	typedef istream_iterator<string> strit;

	ifstream sample("sample_doc.txt");
	ifstream stop("stopwords.txt");
	ofstream results("wordmap.txt");

	SetList<string> s;
	MapArray<string, int> m;

	for_each(strit(stop), strit(),
		[&](const string & word){ s.insert(word); });

	for_each(strit(sample), strit(),
		[&](const string & word){ if (s.find(word) == s.end()) m.insert(word); });

	for_each(m.begin(), m.end(),
		[&](const pair<string, int> & p)
	{ results << setw(15) << left << p.first
	<< right << ": " << p.second << endl; });

	cout << "Results have been sent to txt file." << endl << endl;

	return 0;
}