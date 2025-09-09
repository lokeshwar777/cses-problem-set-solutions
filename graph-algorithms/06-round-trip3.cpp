/* 777 */
#include <bits/stdc++.h>
using namespace std;
// # define int long long

vector<vector<int>> graph;
vector<bool> vis;
vector<int> par, path;

void get_path(int src, int dst) {
    path.push_back(dst);
    for (; src != dst; src = par[src]) path.push_back(src);
    path.push_back(dst);
}

bool dfs(int node, int parent) {
    if (vis[node]) {
        get_path(parent, node);
        return 1;
    }
    par[node] = parent;
    vis[node] = 1;
    for (auto neig : graph[node]) {
        if (neig == parent) continue;
        if (dfs(neig, node)) return 1;
    }

    return 0;
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    graph.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    par.assign(n + 1, -1);
    while (k--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int node = 1; node <= n; node++) {
        if (!vis[node] && dfs(node, -1)) {
            cout << path.size() << '\n';
            for (auto x : path) cout << x << " ";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

signed main() {
    solve();
    return 0;
}