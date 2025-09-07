/* 777 */
#include <bits/stdc++.h>
using namespace std;
// # define int long long

vector<vector<int>> graph;
vector<bool> vis;
vector<int> par;

int bfs(int src, int dst) {
    queue<pair<int, int>> q;
    q.push({1, src});
    vis[src] = 1;
    while (!q.empty()) {
        auto [cur, node] = q.front();
        q.pop();
        if (node == dst) return cur;
        for (auto neig : graph[node]) {
            if (!vis[neig]) {
                vis[neig] = 1;
                q.push({cur + 1, neig});
                par[neig] = node;
            }
        }
    }
    return 0;
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    graph.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    par.assign(n + 1, 0);
    par[0] = -1;
    while (k--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int res = bfs(1, n);
    if (!res) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    vector<string> path;
    for (int node = n; node > 0; node = par[node])
        path.push_back(to_string(node));
    reverse(path.begin(), path.end());
    cout << res << '\n';
    for (auto x : path) cout << x << " ";
}

signed main() {
    solve();
    return 0;
}