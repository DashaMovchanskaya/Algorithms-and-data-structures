#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> metki;
vector<bool> visited;
int n;
int** matr;
int c;

void dfs(int v) {
    visited[v] = true;
    metki[v] = c++;
    for (int i = 1; i <= n; i++) {
        if (matr[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
   
    in >> n;
    matr = new int* [n + 1];
    for (int i = 1; i <= n; i++) {
        matr[i] = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            in >> matr[i][j];
        }
    }

    metki.resize(n + 1, 0);
    visited.resize(n + 1, false);

    c = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        out << metki[i] << " ";
    }

    out.close();
    in.close();

    for (int i = 1; i <= n; i++) {
        delete[] matr[i];
    }
    delete[] matr;
    return 0;
}

