#include <iostream>
#include <vector>
using namespace std;

void DoBuild(const vector<long long>& a, vector<long long>& t, int v, int tl, int tr) {
    if (tr - tl == 1) {
        t[v] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    DoBuild(a, t, 2 * v, tl, m);
    DoBuild(a, t, 2 * v + 1, m, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void DoAdd(vector<long long>& t, int v, int tl, int tr, int i, long long x) {
    if (tr - tl == 1) {
        t[v] += x;
        return;
    }
    int m = (tl + tr) / 2;
    if (i < m) {
        DoAdd(t, 2 * v, tl, m, i, x);
    }
    else {
        DoAdd(t, 2 * v + 1, m, tr, i, x);
    }      
    t[v] = t[2 * v] + t[2 * v + 1];
}
    
long long DoFindSum(const vector<long long>& t, int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int m = (tl + tr) / 2;
    if (r <= m) {
        return DoFindSum(t, 2 * v, tl, m, l, r);
    }
    if (l >= m) {
        return DoFindSum(t, 2 * v + 1, m, tr, l, r);
    }
    long long result = DoFindSum(t, 2 * v, tl, m, l, m) +
        DoFindSum(t, 2 * v + 1, m, tr, m, r);
    return result; 
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);

    vector<long long> T(4 * n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    DoBuild(a, T, 1, 0, n); 
    int q;
    cin >> q;

    while (q > 0) {
        string c;
        cin >> c;
        if (c == "FindSum") {
            int l, r;
            cin >> l >> r;
            long long res = DoFindSum(T, 1, 0, n, l, r);
            cout << res << endl;
        }
        else {
            int ind;
            long long x;
            cin >> ind >> x;
            DoAdd(T, 1, 0, n, ind, x);
        }
        q--;
    }

    return 0;
}

