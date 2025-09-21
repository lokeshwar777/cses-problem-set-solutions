/* 777 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_N = 2e6 + 5;

int dp[MAX_N], sub_sz[MAX_N], N;
vector<int> tree[MAX_N];  // 1-based

void add_edge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

// bottom to top
void dfs(int u, int p = -1) {
    sub_sz[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub_sz[u] += sub_sz[v];
        // here dp is sum of all distances from the nodes in the subtree
        dp[u] += dp[v] + sub_sz[v];
    }
}

// top to bottom
void calc(int u, int par = -1) {
    for (int v : tree[u]) {
        if (v == par) continue;
        dp[v] = dp[u] + N - 2 * sub_sz[v];
        calc(v, u);
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs(1);
    calc(1);
    // for (int i = 1; i <= N; ++i) cout << sub_sz[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= N; ++i) cout << dp[i] << ' ';
}

int32_t main() {
    solve();
    return 0;
}

/*
call it rerooting or DP on trees or whatever

1. compute all the subtree sizes for each node
2. for each negihbour/child the sum of distances to all other nodes (dp[child])
    S = sum of distances of parent to all other nodes (already computed
dp[parent]) X = total nodes - nodes in child subtree = nodes - sub_sz[child] Y =
nodes in child subtree = sub_sz[child] dp[child] = S + X - Y = dp[parent] +
(nodes - sub_sz[child]) - sub_sz[child] dp[child] = dp[parent] + nodes - 2 *
sub_sz[child] dp[v] = dp[u] + n - 2 * sub_sz[v] (before entering into each child
the dp values of parents should be already computed hence top down)
*/