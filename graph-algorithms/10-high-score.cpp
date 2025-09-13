/* 777 */
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

const int MAX_N = 2e6 + 5, INF = 4e18;
int N, M, parent[MAX_N], dist[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> bad;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) {
        g[v].emplace_back(u, w);
    }
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (int i = 1; i <= N; ++i) {
        g[i].clear();
        parent[i] = -1;
        dist[i] = INF;
    }
    bad.reset();
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
}

bool neg_cycle(const vector<Edge>& edges) {
    bool neg = 0;
    for (Edge e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            neg = 1;
            bad[v] = bad[u] = 1;
        }
    }
    return neg;
}

int bellman_ford(int src, const vector<Edge>& edges) {
    dist[src] = 0;
    for (int i = 1; i <= N - 1; ++i) {
        for (Edge e : edges) {
            int u = e.u, v = e.v, w = e.w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    return neg_cycle(edges);  // actual negative cycle check
}

void mark_bad() {
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (bad[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& [v, _] : g[u]) {
            if (bad[v]) continue;
            bad[v] = 1;
            q.push(v);
        }
    }
}

void solve() {
    cin >> N >> M;
    vector<Edge> edges;
    for (int u, v, i = 0; i < M; ++i) {
        int w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, -w);
    }
    build_graph(edges, true);
    int has_neg_cycle = bellman_ford(1, edges);
    mark_bad();
    cout << (bad[N] ? -1 : -dist[N]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

// ALGO
/*
1. consider -weights + maximise becomes minimise
2. use bellman ford to detect -ve cycle
3. if -ve cyl found & (1 ... -ve cyl ... N) => not possible (-1)
4. mark the nodes on or reachable by -ve cyl as bad using DFS/BFS
5. if node N is bad => not possible (-1)
   else return -dist[N]
*/