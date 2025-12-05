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

    vector<int> kan(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        in >> a >> b;
        b--;
        kan[b] = a;
    }

    for (int i = 0; i < n; i++) {
        out << kan[i] << " ";
    }

    return 0;
}
