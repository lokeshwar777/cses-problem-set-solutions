/* 777 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6 + 5;

int par[MAX_N][32];
vector<int> tree[MAX_N];  // 1-based

void add_edge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void bin_lift(int u, int p = -1) {
    par[u][0] = p;
    for (int k = 1; k < 32 && par[u][k - 1] != -1; ++k) {
        par[u][k] = par[par[u][k - 1]][k - 1];
    }
    for (int v : tree[u]) {
        if (v == p) continue;
        bin_lift(v, u);
    }
}

int get_kth(int u, int K) {
    for (int k = 31; k >= 0 && u != -1; --k) {
        if (K & (1 << k)) {
            u = par[u][k];
        }
    }
    return u;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    for (int v = 2; v <= N; ++v) {
        int u;
        cin >> u;
        add_edge(u, v);
    }
    memset(par, -1, sizeof(par));
    bin_lift(1);  // rooted at 1
    vector<int> qs(Q);
    for (int i = 0; i < Q; ++i) {
        int u, k;
        cin >> u >> k;
        int res = get_kth(u, k);
        qs[i] = res;
    }

    for (int q : qs) cout << q << '\n';
}

int32_t main() {
    solve();
    return 0;
}

/*
root the tree and precompute the props of ancestors using binary lifting

for each node we compute parent[node][2^kth ancestor] where k from 0 to 31
parent[node][0] = par
for k: 1->31
    parent[node][k] = parent[parent[node][k - 1]][k - 1]
    (if parent[node][k - 1] exists)
if you want kth power at the current node, go to the node at k-1th power and
ask it who is the node at k-1th power from you
*/