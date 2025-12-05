#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int FindSet(int x, vector<int>& parent) {
    if (x == parent[x])
        return x;

    return parent[x] = FindSet(parent[x], parent);
}

void Union(int x, int y, vector<int>& parent, vector<int>& size, int& comp) {
    x = FindSet(x, parent);
    y = FindSet(y, parent);
    if (x != y) {
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        comp--;
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, q;
    in >> n >> m >> q;
    bool sv = false;
    int comp = n; 
    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<int> Us(m + 1);
    vector<int> Vs(m + 1);
    for (int i = 1; i <= m; i++) {
        in >> Us[i];
        in >> Vs[i]; 
    }

    vector<int> x(q);
    vector<bool> isX(m + 1, false); 
    for (int i = 0; i < q; i++) {
        in >> x[i];
        isX[x[i]] = true;
    }

    for (int i = 1; i <= m; ++i) {
        if (!isX[i]) {
            Union(Us[i], Vs[i], parent, size, comp);
        }
    }

    int k = q - 1; 
    vector<int> Out(q);
    while (k >= 0) {
        if (comp == 1) {
            Out[k] = 1;
        }
        else {
            Out[k] = 0;
        }
        
        Union(Us[x[k]], Vs[x[k]], parent, size, comp);
        k--; 
    }

    for (int i = 0; i < q; ++i) {
        out << Out[i];
    }
    out << endl; 
    out.close();
    return 0;
}
