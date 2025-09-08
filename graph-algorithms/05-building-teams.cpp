/* 777 */
#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

const int MAX_N = 2e6 + 5, INF = 1e9 + 5;  // use 1e18 + 5 for larger values
int N, M, colors[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) {
        g[v].emplace_back(u, w);
    }
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (int i = 1; i <= N; ++i) {
        g[i].clear();
        colors[i] = -1;
    }
    vis.reset();
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
}

// or is_bipartite
bool coloring_DFS(int u, int p = -1, int cur = 0) {
    if (colors[u] != -1) return colors[u] == cur;
    colors[u] = cur;
    for (auto& [v, w] : g[u]) {
        if (v == p) continue;
        if (!coloring_DFS(v, u, !cur)) return 0;
    }
    return 1;
}

void solve() {
    cin >> N >> M;
    vector<Edge> edges;
    for (int u, v, i = 0; i < M; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v, 1);
    }

    // ---BUILD---
    build_graph(edges, false);

    // ---COLORING---
    for (int i = 1; i <= N; ++i) {
        if (colors[i] != -1) continue;
        int possible = coloring_DFS(i);
        if (!possible) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for (int i = 1; i <= N; ++i) cout << colors[i] + 1 << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}