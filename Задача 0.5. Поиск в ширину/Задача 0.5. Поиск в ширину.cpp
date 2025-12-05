#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int** matr = new int* [n];
    for (int i = 0; i < n; i++) {
        matr[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matr[i][j]; 
        }
    }

    vector<bool> vis(n, false);
    vector<int> m(n, 0); 
    int count = 0; 

    for (int j = 0; j < n; j++) {
        if (!vis[j]) {
            queue<int> q;
            q.push(j); 
            vis[j] = true; 
            m[j] = ++count; 
            while (!q.empty()) {
                int p = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    if (matr[p][i] == 1 && !vis[i]) {
                        q.push(i);
                        count++;
                        m[i] = count;
                        vis[i] = true;
                    }
                }
            }
        }
    }

    for (int v : m) {
        out << v << " ";
    }

    out.close();
    for (int i = 0; i < n; i++) {
        delete[] matr[i];
    }
    delete[] matr;

    return 0;
}

