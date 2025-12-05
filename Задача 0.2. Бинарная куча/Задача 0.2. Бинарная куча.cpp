#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;

	long long* arr = new long long[n];

	for (int i = 0; i < n; i++) {
		in >> arr[i];
	}

	for (int i = 0; i < n / 2; i++) {
		if ((2 * i + 1 < n && arr[i] > arr[2 * i + 1]) || (2 * i + 2 < n && arr[i] > arr[2 * i + 2])) {
			out << "No";
			delete[] arr;
			return 0;
		}
	}

	out << "Yes";
	delete[] arr;
	return 0;
}