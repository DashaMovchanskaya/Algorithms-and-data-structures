#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Road {
    int r, t; 
};

struct Cross {
    int n, pr;
    long long minT;

    bool operator>(const Cross& other) const {
        return minT > other.minT;
    }
};

vector<Point> cross;
vector<vector<Road>> list;

bool Left(int prev, int cur, int next) { 
    long long dx1 = cross[cur].x - cross[prev].x;
    long long dy1 = cross[cur].y - cross[prev].y;
    long long dx2 = cross[next].x - cross[cur].x;
    long long dy2 = cross[next].y - cross[cur].y;

    long long cross = dx1 * dy2 - dy1 * dx2;

    if (cross == 0) {
        if (dx1* dx2 + dy1 * dy2 < 0) {
            return true; 
        }
        return false; 
    }

    return cross > 0;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, K;
    in >> N >> M >> K;

    cross.resize(N + 1); 
    list.resize(N + 1); 

    for (int i = 1; i <= N; i++) {
        int a, b;
        in >> a >> b;
        cross[i] = { a, b };
    }

    for (int i = 1; i <= M; i++) {
        int p, r, t;
        in >> p >> r >> t; 
        list[p].push_back({ r, t });
        list[r].push_back({ p, t });  
    }

    int A, B;
    in >> A >> B;

    cross[0].x = cross[A].x;
    cross[0].y = cross[A].y - 1;

    priority_queue<Cross, vector<Cross>, greater<Cross>> pq;
    pq.push({ A, 0, 0 });
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INT64_MAX));
    dist[A][0] = 0;
     
    while (!pq.empty()) {
        Cross c = pq.top();
        pq.pop();

        if (c.minT > dist[c.n][c.pr]) continue;
        if (c.n == B) break;

        for (auto v : list[c.n]) {
            long long wait = 0;
            if (c.pr != -1 && Left(c.pr, c.n, v.r)) {
                wait = list[c.n].size() * K;
            }

            long long newDist = c.minT + v.t + wait;

            if (newDist < dist[v.r][c.n]) {
                dist[v.r][c.n] = newDist;
                pq.push({ v.r, c.n, newDist }); 
            }
        }

    }

    long long ans = INT64_MAX; 
    for (int prev = 0; prev <= N; prev++) {
        ans = min(ans, dist[B][prev]);
    }
    if (ans == INT64_MAX) { 
        out << "No\n";
    }
    else {
        out << "Yes\n" << ans << "\n";
    }


    return 0;
}


