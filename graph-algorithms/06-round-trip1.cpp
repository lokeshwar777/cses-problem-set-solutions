/* 777 */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

const int MAX_N = 2e6 + 5, INF = 1e9 + 5;
int N, M, parent[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;
vector<int> cycle_path;

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
}

vector<int> get_path(int src, int dst) {
    vector<int> path;
    while (dst && (path.empty() || dst != src)) {
        path.push_back(dst);
        dst = parent[dst];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

bool has_cycle_DFS_undir(int u, int p = -1) {
    vis[u] = 1;
    parent[u] = p;

    for (auto& [v, w] : g[u]) {
        if (v == p) continue;
        if (vis[v]) {
            cycle_path = get_path(v, u);
            cycle_path.push_back(v);
        }
        if (vis[v] || has_cycle_DFS_undir(v, u)) return 1;
    }

    return 0;
}

void solve() {
    cin >> N >> M;
    vector<Edge> edges;
    edges.reserve(M);
    for (int u, v, i = 0; i < M; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v, 1);
    }
    build_graph(edges, false);
    bool has_cycle = 0;
    for (int i = 1; i <= N && !has_cycle; ++i) {
        if (vis[i]) continue;
        has_cycle |= has_cycle_DFS_undir(i);
    }
    if (!has_cycle) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << (int) cycle_path.size() << '\n';
    for (int x : cycle_path) cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}