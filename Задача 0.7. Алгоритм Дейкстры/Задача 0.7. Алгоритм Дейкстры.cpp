#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

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

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M;
    in >> N >> M;

    vector<vector<Road>> graph; 
    graph.resize(N + 1);  

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        in >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({ a, c }); 
    }

    priority_queue<Cross, vector<Cross>, greater<Cross>> pq;
    pq.push({ 1, 0, 0 });
    vector<long long> dist(N + 1, INT64_MAX);
    dist[1] = 0;
    vector<bool> proc(N + 1, false);

    while (!pq.empty()) {
        Cross c = pq.top();
        pq.pop();

        if (proc[c.n]) continue;
        proc[c.n] = true;

        for (auto v : graph[c.n]) { 
            if (dist[c.n] + v.t < dist[v.r]) {
                dist[v.r] = dist[c.n] + v.t; 
                pq.push({ v.r, c.n, dist[c.n] + v.t }); 
            }
        }

    }

    out << dist[N];

    out.close();

    return 0;
}


