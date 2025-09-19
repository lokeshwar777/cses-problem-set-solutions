/* 777 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
int dep[MAX_N];
vector<int> g[MAX_N];
int N;

// populates depth array of each node from the `src` node
void calcDepth(int u, int par) {
    for (int v : g[u]) {
        if (v == par) continue;
        dep[v] = dep[u] + 1;
        calcDepth(v, u);
    }
}

// returns {height, farthest node} of tree rooted at `src`
pair<int, int> getHeight(int src) {
    calcDepth(src, -1);
    int fn = 1, mxd = 0;  // fn-farthest node, mxd-max depth
    for (int i = 1; i <= N; ++i) {
        if (dep[i] > mxd) {
            mxd = dep[i];
            fn = i;
        }
    }
    return make_pair(mxd, fn);
}

int getDiameter() {
    auto [ht, far] =
        getHeight(1);  // get the farthest node from any random node
    memset(dep, 0, sizeof(dep));
    auto [diam, _] = getHeight(far);  // max dist from farthest node is diameter
    return diam;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << getDiameter();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}