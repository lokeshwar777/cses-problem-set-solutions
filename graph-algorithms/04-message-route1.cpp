/* 777 */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
};

const int MAX_N = 2e6 + 5;
int N, M, par[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) g[v].emplace_back(u, w);
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
}

int shortest_bfs(int src, int dest) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    for (int lvl = 1; !q.empty(); lvl++) {
        for (int sz = q.size(); sz; --sz) {
            int u = q.front();
            q.pop();
            if (u == dest) return lvl;
            for (auto& [v, w] : g[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
                par[v] = u;
            }
        }
    }
    return -1;
}

vector<int> get_path(int src, int dest) {
    vector<int> path;
    for (int u = src; u != dest; u = par[u]) path.push_back(u);
    path.push_back(dest);
    reverse(path.begin(), path.end());
    return path;
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
    int len = shortest_bfs(1, N);
    if (len < 0) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << len << '\n';
    vector<int> path = get_path(N, 1);
    for (int u : path) cout << u << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}