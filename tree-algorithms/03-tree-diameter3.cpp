/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vector<int> get_depth(int root, vector<vector<int>> &adj, int n) {
    vector<int> depth(n, 0);
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto &child : adj[node]) {
            if (child == par) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    };
    dfs(root, -1);
    return depth;
}

int get_diameter(vector<vector<int>> &adj, int n) {
    int random = 0;
    vector<int> depth;
    depth = get_depth(random, adj, n);
    int max_depth = -1, end_node = -1;
    for (int i = 0; i < n; ++i) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
            end_node = i;
        }
    }
    depth = get_depth(end_node, adj, n);
    int diameter = -1;
    for (auto &x : depth) diameter = max(diameter, x);
    return diameter;
}

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << get_diameter(adj, n);
}

int32_t main() {
    FAST_IO
    solve();
}