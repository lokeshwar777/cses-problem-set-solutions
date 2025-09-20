/* 777 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e6 + 5;

int downward[MAX_N], upward[MAX_N];
vector<int> tree[MAX_N];  // 1-based

void add_edge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int dfs1(int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u);
        downward[u] =
            max(downward[u],
                downward[v] + 1);  // max height of the subtree rooted at `u`
    }
    return 0;
}

int dfs2(int u, int p = -1) {
    vector<int> &nbrs = tree[u];  // neighbors
    int sz = nbrs.size();
    vector<int> pref_mx(sz, 0), suff_mx(sz, 0);
    for (int i = 0, mx = 0; i < sz; ++i) {  // compute prefix
        int v = nbrs[i];
        if (v != p) mx = max(mx, downward[v]);
        if (i) mx = max(mx, pref_mx[i - 1]);
        pref_mx[i] = mx;
    }
    for (int i = sz - 1, mx = 0; i >= 0; --i) {  // compute suffix
        int v = nbrs[i];
        if (v != p) mx = max(mx, downward[v]);
        if (i < sz - 1) mx = max(mx, suff_mx[i + 1]);
        suff_mx[i] = mx;
    }
    for (int i = 0; i < sz; ++i) {  // consider the max
        int v = nbrs[i];
        if (v == p) continue;
        upward[v] = upward[u] + 1;  // do not use `if (p != -1)`
        if (i) upward[v] = max(upward[v], 2 + pref_mx[i - 1]);
        if (i < sz - 1) upward[v] = max(upward[v], 2 + suff_mx[i + 1]);
    }
    for (int v : nbrs) {
        if (v == p) continue;
        dfs2(v, u);
    }
    // for (int i = 0; i < sz; ++i) cout << nbrs[i] << " " << pref_mx[i] << " "
    // << suff_mx[i] << endl;
    return 0;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= N; ++i) cout << max(downward[i], upward[i]) << ' ';
}

int32_t main() {
    solve();
    return 0;
}

/*
the path to the farthest node from each node can exist only in 2 ways
    1. through its subtree (below/downwards)
    2. through its parent (above/upwards)

dfs1 - downwards
    - compute the height of each node
    - this gives the distance of farthest node in subtree

dfs2 - upwards
    - A = upward of parent + 1
    - B = consider the maximum of heights of all the siblings of the current
node (in other words maximum of all the chidren of the parent of current node
except the current node and grand parent)
    - upward of current node = max(A, B)

answer is max(upward, downward) for each node
*/