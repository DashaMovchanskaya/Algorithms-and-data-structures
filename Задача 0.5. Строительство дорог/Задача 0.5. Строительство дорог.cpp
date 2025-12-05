#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int FindSet(int x, vector<int>& parent) {
    if (x == parent[x])
        return x;
    
    return parent[x] = FindSet(parent[x], parent);
}

void Union(int x, int y, vector<int>& parent, vector<int>& size, int& count) {
    x = FindSet(x, parent); 
    y = FindSet(y, parent); 
    if (x != y) {
        if (size[x] < size[y])
            std::swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        count--;
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, q;
    in >> n >> q;
    int count = n;
    vector<int> parent(n + 1); 
    vector<int> size(n + 1, 1); 

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q > 0) {
        int u, v;
        in >> u >> v;
        Union(u, v, parent, size, count);       
        out << count << endl; 
        q--;
    }

    out.close();
    return 0;
}
