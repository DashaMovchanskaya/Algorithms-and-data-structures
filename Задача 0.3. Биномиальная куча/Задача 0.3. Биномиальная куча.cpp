#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	long long n;
	in >> n;
	in.close();

	vector<int> ost;

	long long k = n;
	while (k > 0) {
		ost.push_back(k % 2);
		k /= 2;
	}

	for (int i = 0; i < ost.size(); i++) {
		if (ost[i] == 1) {
			out << i << endl;
		}
	}

	out.close();
	return 0;
}
