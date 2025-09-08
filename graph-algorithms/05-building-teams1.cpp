/* 777 */
#include <bits/stdc++.h>
using namespace std;
// # define int long long

vector<vector<int>> graph;
vector<int> color;
vector<bool> vis;
bool notValid = 0;

void dfs(int node, int clr) {
    notValid |= vis[node] && color[node] != (clr + 1);
    if (vis[node]) return;
    color[node] = clr + 1;
    vis[node] = 1;
    for (auto neig : graph[node]) {
        dfs(neig, clr ^ 1);
    }
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    graph.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    while (k--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int node = 1; node <= n; node++)
        if (!vis[node]) dfs(node, 0);
    if (notValid)
        cout << "IMPOSSIBLE";
    else
        for (int node = 1; node <= n; node++) cout << color[node] << " ";
    cout << '\n';
}

signed main() {
    solve();
    return 0;
}