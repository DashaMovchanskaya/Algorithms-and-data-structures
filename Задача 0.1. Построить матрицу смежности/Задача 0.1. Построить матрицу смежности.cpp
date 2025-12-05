#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    int** matrSm = new int* [n];
    for (int i = 0; i < n; i++) { 
        matrSm[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrSm[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b; 
        a--; b--;
        matrSm[a][b] = 1;
        matrSm[b][a] = 1; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << matrSm[i][j] << " ";
        }
        out << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrSm[i];
    }
    delete[] matrSm;

    return 0;
}
