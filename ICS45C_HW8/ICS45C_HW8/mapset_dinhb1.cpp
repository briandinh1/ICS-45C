#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	typedef istream_iterator<string> strit;

	ifstream sample("sample_doc.txt");
	ifstream stop("stopwords.txt");
	ofstream results("wordmap.txt");

	set<string> s;
	map<string, int> m;

	copy(strit(stop), strit(), inserter(s, s.begin()));

	for_each(strit(sample), strit(),
		[&](const string & word){ if (s.find(word) == s.end()) ++m[word]; });

	for_each(m.begin(), m.end(), [&](const pair<string, int> & p)
	{ results << setw(15) << left << p.first
	<< right << ": " << p.second << endl; });

	cout << "Results have been sent to txt file." << endl << endl;

	return 0;
}