#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point { 
    int x;
    int y;

    Point() {};
    Point(int a, int b) : x(a), y(b) {};
};

bool isValid(int i, int j, int n, int m) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

bool isExit(int i, int j, const vector<int>& exits, int n) {
    if (i != n) return false;
    return find(exits.begin(), exits.end(), j) != exits.end();
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m, k; 
    in >> n >> m >> k;

    int** matr = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        matr[i] = new int[m + 1];
    }
    vector<int> enter(k);
    vector<int> exit(k); 

    for (int i = 0; i < k; i++) {
        in >> enter[i];
    }
    for (int i = 0; i < k; i++) {
        in >> exit[i]; 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            in >> matr[i][j];
        }
    }

    int** d = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        d[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            d[i][j] = -1;
        }
    }

    queue<Point> q_pr;

    for (int i = 0; i < k; i++) {
        if (matr[n][exit[i]] == 0) {
            d[n][exit[i]] = 0;
            q_pr.push({ n, exit[i] });
        }
    }

    while (!q_pr.empty()) {
        Point p = q_pr.front();
        q_pr.pop();

        Point down, up, l, r; 
        down.x = p.x + 1; down.y = p.y;
        up.x = p.x - 1; up.y = p.y;
        l.x = p.x; l.y = p.y - 1;
        r.x = p.x; r.y = p.y + 1;

        if (isValid(down.x, down.y, n, m) && matr[down.x][down.y] == 0 && d[down.x][down.y] == -1) {
            d[down.x][down.y] = d[p.x][p.y] + 1;
            q_pr.push(down);
        }
        if (isValid(l.x, l.y, n, m) && matr[l.x][l.y] == 0 && d[l.x][l.y] == -1) {
            d[l.x][l.y] = d[p.x][p.y] + 1;
            q_pr.push(l);
        }
        if (isValid(r.x, r.y, n, m) && matr[r.x][r.y] == 0 && d[r.x][r.y] == -1) {
            d[r.x][r.y] = d[p.x][p.y] + 1;
            q_pr.push(r);
        }
        if (isValid(up.x, up.y, n, m) && matr[up.x][up.y] == 0 && d[up.x][up.y] == -1) {
            d[up.x][up.y] = d[p.x][p.y] + 1;
            q_pr.push(up);
        }
    }

    int count = 0; 
    int dx[4] = { 0, 1, 0, -1 };  
    int dy[4] = { -1, 0, 1, 0 }; 

    queue<Point> pq;
    for (int z = 0; z < k; z++) { 
        if (matr[1][enter[z]] == 0 && d[1][enter[z]] != -1) {
            pq.push({1, enter[z]});
            bool passed = false;
            int t = 1;
            int i = 1, j = enter[z];

            vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

            visited[1][enter[z]] = true; 

            queue<Point> q;
            q.push({ i, j });

            while (!passed) {
                if (i == n) {
                    for (int ex : exit) {
                        if (j == ex) {
                            count++;
                            passed = true;
                            while (!q.empty()) {
                                Point p = q.front();
                                matr[p.x][p.y] = z + 2; 
                                q.pop();
                            }
                            break;
                        }
                    }
                }

                if (passed) break;

                bool moved = false;
                for (int attempt = 0; attempt < 4; attempt++) {
                    int new_t;
                    switch (attempt) {
                    case 0: new_t = (t + 3) % 4; break;
                    case 1: new_t = t; break;
                    case 2: new_t = (t + 1) % 4; break;
                    case 3: new_t = (t + 2) % 4; break;
                    }

                    int ni = i + dx[new_t]; 
                    int nj = j + dy[new_t]; 

                    if (isValid(ni, nj, n, m)) {
                        if ((isExit(ni, nj, exit, n) && matr[ni][nj] != 1) || matr[ni][nj] == 0) {
                            i = ni;
                            j = nj;
                            t = new_t;
                            visited[i][j] = true;
                            q.push(Point(i, j));
                            moved = true;
                            break;
                        }
                    }
                }

                if (!moved) {
                    break;
                }
            }
        }
    }

    out << count << endl; 

    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) { 
            out << matr[i][j] << " "; 
        }
        out << endl; 
    }

    out.close(); 

    return 0;
}
