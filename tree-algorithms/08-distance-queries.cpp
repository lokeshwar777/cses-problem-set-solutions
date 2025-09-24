/* 777 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6 + 5, LOG = 20;

int up[MAX_N][LOG], dep[MAX_N];
vector<int> g[MAX_N];  // 1-based

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
    int x = dep[a], y = dep[b];  // x-depth of a, y-depth of b
    if (x > y)
        a = kth_ancestor(a, x - y);
    else if (y > x)
        b = kth_ancestor(b, y - x);
    while (a != b) {
        int k = LOG - 1;
        while (k > 0 && up[a][k] == up[b][k]) k--;
        a = up[a][k];
        b = up[b][k];
    }
    return a;
}

int distance(int a, int b) {
    int x = lca(a, b);  // x-lowest common ancestor of a & b
    return dep[a] + dep[b] - 2 * dep[x];
}

void solve() {
    // 1. Take Input
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    // 2. Build the 2D parent matrix using binary lifting
    build(1);  // rooted at 1

    // 3. Perform queries
    vector<int> qs(Q);
    for (int i = 0, a, b; i < Q; ++i) {
        cin >> a >> b;
        int res = distance(a, b);
        qs[i] = res;
    }

    for (int q : qs) cout << q << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}