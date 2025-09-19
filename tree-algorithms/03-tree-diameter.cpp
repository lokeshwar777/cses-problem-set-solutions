/* 777 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6 + 5;

vector<int> tree[MAX_N];  // 1-based

void add_edge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

// passing diameter by reference
int diam_dfs(int u, int p, int &best) {
    int f_max = 0, s_max = 0;
    for (int v : tree[u]) {
        if (v == p) continue;
        int v_ht = diam_dfs(v, u, best);
        if (v_ht >= f_max) {
            s_max = f_max, f_max = v_ht;
        } else if (v_ht > s_max) {
            s_max = v_ht;
        }
    }
    best = max(best, f_max + s_max);
    // cout << u << " " << f_max << " " << s_max << " " << best << endl;
    return f_max + 1;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // u++;v++ // for 0-based nodes
        add_edge(u, v);
    }

    int diam = 0;
    diam_dfs(1, -1, diam);
    cout << diam;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}