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
    // lg1 - first largest, lg2 - second largest, v1 - origin/node of lg1, v2 -
    // origin/node of lg2;
    int lg1 = 0, v1 = -1, lg2 = 0, v2 = -1;
    for (int v : nbrs) {
        if (v == p) continue;
        int x = downward[v];
        if (x >= lg1) {
            lg2 = lg1;
            lg1 = x;
            v2 = v1;
            v1 = v;
        } else if (x > lg2) {
            lg2 = x;
            v2 = v;
        }
    }
    for (int v : nbrs) {
        if (v == p) continue;
        // cout << v << " " << lg1 << " " << v1 << " " << lg2 << endl;
        upward[v] = upward[u] + 1;
        // the following conditions are important for edge cases
        if (v1 != -1 && v != v1) {
            upward[v] = max(upward[v], 2 + lg1);
        } else if (v2 != -1) {
            upward[v] = max(upward[v], 2 + lg2);
        }
    }
    for (int v : nbrs) {
        if (v == p) continue;
        dfs2(v, u);
    }
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

dfs1 - downwards (bottom up / bottom to top)
    - compute the height of each node
    - this gives the distance of farthest node in subtree

dfs2 - upwards (top down / top to bottom)
    - A = upward of parent + 1
    - B = consider largest 2 values and their origin so that if it came from the
current node we can ignore it
    - upward of current node = max(A, B)

answer is max(upward, downward) for each node
*/