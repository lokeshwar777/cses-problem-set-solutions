/* 777 */
#include <bits/stdc++.h>
using namespace std;
// # define int long long

vector<vector<int>> graph;
vector<bool> vis;

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = 1;
    for (auto neig : graph[node]) {
        dfs(neig);
    }
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    graph.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    while (k--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<string> edges;
    int cnt = 0, prev = 0;
    for (int node = 1; node <= n; ++node) {
        if (vis[node]) continue;
        if (prev)
            edges.push_back(to_string(prev) + ' ' + to_string(node) + '\n');
        dfs(node);
        cnt++;
        prev = node;
    }
    cnt--;

    cout << cnt << '\n';
    for (auto &edge : edges) cout << edge;
}

signed main() {
    solve();
    return 0;
}