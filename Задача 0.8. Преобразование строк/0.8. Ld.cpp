#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in ("in.txt");
    ofstream out("out.txt");

    int x, y, z;
    in >> x >> y >> z;

    string A, B;
    in >> A;
    in >> B;

    int** F = new int* [A.size() + 1];
    for (int i = 0; i <= A.size(); i++) {
        F[i] = new int[B.size() + 1];
    }

    for (int i = 0; i <= A.size(); i++) {
        F[i][0] = i * x;
    }

    for (int j = 0; j <= B.size(); j++) { 
        F[0][j] = j * y;
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            int d = 0;
            if (A[i] != B[j]) {
                d = 1;
            }
            int a = F[i][j + 1] + x; 
            int b = F[i + 1][j] + y; 
            int c = F[i][j] + d * z; 
            F[i + 1][j + 1] = min(min(a, b), c); 

        }
    }

    out << F[A.size()][B.size()];

    for (int i = 0; i < A.size(); i++) {
        delete[] F[i];
    }
    delete[] F;
    return 0;
}

