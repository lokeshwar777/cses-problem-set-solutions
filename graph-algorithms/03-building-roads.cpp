/* 777 */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
};

const int MAX_N = 2e6 + 5;
int N, M;
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;
vector<int> vec;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) g[v].emplace_back(u, w);
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto& [v, w] : g[u]) {
        dfs(v);
    }
}

int conn_cmpts() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (vis[i]) continue;
        dfs(i);
        cnt++;
        vec.push_back(i);
    }
    return cnt;
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
    int cmpts = conn_cmpts();
    cout << (cmpts - 1) << '\n';
    for (int i = 1; i < cmpts; ++i) cout << vec[i - 1] << ' ' << vec[i] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}