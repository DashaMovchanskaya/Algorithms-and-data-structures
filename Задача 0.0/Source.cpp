#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	long long number;
	vector<long long> numbers;

	while (in >> number) {
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());

	long long sum = numbers[0];

	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i - 1] < numbers[i]) {
			sum += numbers[i];
		}
	}

	out << sum;

	return 0;
}
