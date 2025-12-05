#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int** matrSm = new int* [n];
    for (int i = 0; i < n; i++) {
        matrSm[i] = new int[n];
        for (int j = 0; j < n; j++) {
            in >> matrSm[i][j];
        }
    }

    vector<int> kan(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            if (matrSm[i][j] == 1) {
                kan[j] = i + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        out << kan[i] << " ";
    }

    for (int i = 0; i < n; i++) {
        delete[] matrSm[i];
    }
    delete[] matrSm;

    return 0;
}
