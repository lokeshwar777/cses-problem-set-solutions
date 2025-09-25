/* 777 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6 + 5, LOG = 20;

int up[MAX_N][LOG], dep[MAX_N];
vector<int> g[MAX_N], xtra, paths;  // 1-based

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void build(int u, int p = -1) {
    up[u][0] = p;
    for (int k = 1; k < LOG; ++k) {
        up[u][k] = up[u][k - 1] != -1 ? up[up[u][k - 1]][k - 1] : -1;
    }
    for (int v : g[u]) {
        if (v == p) continue;
        dep[v] = 1 + dep[u];
        build(v, u);
    }
}

int kth_ancestor(int u, int K) {
    for (int k = 0; k < LOG && u != -1; ++k) {
        if (K & (1 << k)) u = up[u][k];
    }
    return u;
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    a = kth_ancestor(a, dep[a] - dep[b]);
    if (a == b) return a;
    // lift both a and b until just before LCA
    for (int k = LOG - 1; k >= 0; --k) {
        if (up[a][k] != up[b][k]) {
            a = up[a][k];
            b = up[b][k];
        }
    }
    return up[a][0];  // parent is LCA
}

void dfs(int u = 1, int p = -1) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        paths[u] += paths[v] - xtra[v];
    }
}

void solve() {
    // 1. Take Input
    int N, P;
    cin >> N >> P;

    xtra.resize(N + 1, 0);
    paths.resize(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // u++;v++ // for 0-based nodes
        add_edge(u, v);
    }

    // 2. Build the 2D parent matrix using binary lifting
    build(1);  // rooted at 1

    for (int i = 0; i < P; ++i) {
        int u, v;
        cin >> u >> v;
        paths[u]++, paths[v]++;
        int l = lca(u, v);
        paths[l]--;
        xtra[l]++;
    }

    dfs();

    for (int i = 1; i <= N; ++i) cout << paths[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

/*
in a tree the path between 2 nodes only passes through their LCA
this means we can hang the path at LCA
all the nodes above LCA(a, b) are not included in the path
so if we do +1 at a, +1 at b, we need to avoid double counting
-1 at LCA(a, b) and still -1 as extra at LCA(a, b) for its parent
*/