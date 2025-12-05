#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int LowerBound(vector<int>& numbers, int x) {
    int begin = 0, end = numbers.size();
    int faund = numbers.size(); 
    int middle = 0; 
    while (begin < end) {
        middle = (begin + end) / 2;
        if (x <= numbers[middle]) {
            faund = middle;
            end = middle;
        }
        else {
           begin = middle + 1;
        }
    }

    return faund;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        in >> A[i];
    }

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int index = LowerBound(dp, A[i]);
        if (index == dp.size()) { 
            dp.push_back(A[i]);
        }
        else {
            dp[index] = A[i];
        }
    }

    out << dp.size();

    in.close();
    out.close();
    return 0;
}
