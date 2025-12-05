#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<int> count(n, 0); 
    vector<vector<int>> list(n); 

    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        a--;
        list[a].push_back(b);
        a++; b--;
        list[b].push_back(a); 
    }

    for (int i = 0; i < n; i++) {
        out << list[i].size() << " ";
        for (int j = 0; j < list[i].size(); j++) { 
            out << list[i][j] << " ";
        }
        out << endl;
    }

    return 0;
}
