/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n;
vector<int> subtree_sz, dist_sum;
vector<vector<int>> adj;

int root_dist_sum(int node, int par, int depth) {
    int cnt = depth;
    subtree_sz[node] = 1;
    for (int child : adj[node]) {
        if (child == par) continue;
        cnt += root_dist_sum(child, node, depth + 1);
        subtree_sz[node] += subtree_sz[child];
    }
    // cout << node << " " << par << " " << cnt << endl;
    return cnt;
}

void treeDP(int node, int par) {
    if (node != par)
        dist_sum[node] =
            dist_sum[par] + (n - subtree_sz[node]) - subtree_sz[node];
    for (int child : adj[node]) {
        if (child == par) continue;
        treeDP(child, node);
    }
}

void solve() {
    cin >> n;
    adj.resize(n, vector<int>());
    subtree_sz.resize(n);
    dist_sum.resize(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    dist_sum[root] = root_dist_sum(root, root, 0);
    treeDP(0, 0);
    for (int x : dist_sum) cout << x << " ";
}

int32_t main() {
    FAST_IO
    solve();
}