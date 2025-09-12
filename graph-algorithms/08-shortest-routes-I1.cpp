// TLE CODE

/* 777 */
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

struct Node {
    int u, cst;
    Node(int node, int cost) : u(node), cst(cost) {}

    // max-heap
    bool operator<(const Node& other) const { return cst > other.cst; };

    // min-heap
    // bool operator<(const Node& other) const { return cst < other.cst; };
};

const int MAX_N = 2e6 + 5, INF = 1e18 + 5;
int N, M, parent[MAX_N], dist[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) {
        g[v].emplace_back(u, w);
    }
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
        dist[i] = INF;
    }
}

// O(V ^ 2) for dense graphs, array-based - SSSP
vector<int> dijkstra_dense(int src = 1) {
    dist[src] = 0;

    for (int i = 1; i <= N; ++i) {
        int u = -1;
        for (int j = 1; j <= N; ++j) {
            if (vis[j] || dist[j] == INF) continue;
            if (u == -1 || dist[u] > dist[j]) u = j;
        }
        if (u == -1) break;
        vis[u] = 1;
        for (auto& [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    return vector<int>(dist + 1, dist + N + 1);
}

void solve() {
    cin >> N >> M;
    vector<Edge> edges;
    for (int u, v, i = 0; i < M; ++i) {
        int w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    build_graph(edges, true);

    vector<int> dists = dijkstra_dense(1);
    for (int x : dists) cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    solve();
}