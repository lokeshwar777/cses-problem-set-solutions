/* 777 */

#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int MAX_N = 2e6 + 5;
// LCA
int dep[MAX_N], first[MAX_N];
vector<int> euler;

// ---------------- Sparse Table -------------
int highestPowerOf2(uint32_t x) {
    return 31 - __builtin_clz(x);
}
class SparseTable {
    int N, L;
    vector<vector<int>> table;

   public:
    SparseTable(int n) {
        this->N = n;
        this->L = highestPowerOf2(n) + 1;
        this->table.resize(n, vector<int>(this->L, -1));
        // table[i][k] -> stores the index in the euler tour which has minimum
        // depth of `2^k` elements from `i`
    }

    void build() {
        for (int i = 0; i < N; ++i) {
            table[i][0] = i;
        }
        for (int k = 1; k < L; ++k) {
            for (int i = 0; i < N - (1 << k) + 1; ++i) {
                int x = table[i][k - 1], y = table[i + (1 << (k - 1))][k - 1];
                int dx = dep[euler[x]], dy = dep[euler[y]];
                table[i][k] = dx < dy ? x : y;
            }
        }
    }

    int query(int l, int r) {
        int k = highestPowerOf2(r - l + 1);
        int x = table[l][k], y = table[r - (1 << k) + 1][k];
        int dx = dep[euler[x]], dy = dep[euler[y]];
        return dx < dy ? x : y;
    }
};

// ---------------- declare ----------------------

int N;
vector<int> tree[MAX_N];  // 1-based
SparseTable* SPT;         // 0-based

// ---------------- build ----------------------

void add_edge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void reset_tree(int n) {
    for (int i = 0; i <= n; ++i) {
        tree[i].clear();
        dep[i] = 0;
        first[i] = -1;
    }
    euler.clear();
    delete SPT;
}

// ----------------- 2N ETT ---------------------

// assign in (entry) and out (exit) times
void euler_dfs(int u = 1, int p = -1) {
    if (p != -1) dep[u] = dep[p] + 1;
    if (first[u] == -1) first[u] = (int) euler.size();
    euler.push_back(u);
    for (int v : tree[u]) {
        if (v == p) continue;
        euler_dfs(v, u);
        euler.push_back(u);
    }
}

// ----------------- operations ----------------------

int lca(int a, int b) {
    int l = first[a], r = first[b];
    if (l > r) swap(l, r);
    int idx = SPT->query(l, r);  //  index of min(depth[l..r]) in euler[l..r]
    return euler[idx];
}

// ----------------- debug ----------------------

void print_DS() {
    for (int i = 1; i <= N; ++i) cout << i << " ";
    cout << endl;
    for (int i = 1; i <= N; ++i) cout << dep[i] << " ";
    cout << endl;
    for (int x : euler) cout << x << " ";
    cout << endl;
}

// ----------------- code ----------------------

void solve() {
    int Q;
    cin >> N >> Q;

    reset_tree(N);  // in case of multiple test cases

    for (int v = 2; v <= N; ++v) {
        int u;
        cin >> u;
        add_edge(u, v);
    }

    // ETT (Euler Tour in Trees) or Tree Flattening or In-Out - Subtree Queries
    euler_dfs();

    // LCA
    SPT = new SparseTable((int) euler.size());
    SPT->build();

    vector<int> qs(Q);
    for (int i = 0, a, b; i < Q; ++i) {
        cin >> a >> b;
        int res = lca(a, b);
        qs[i] = res;
    }

    for (int x : qs) cout << x << '\n';

    // ---DEBUG---
    // print_DS();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T; // multiple test cases
    while (T--) solve();
    return 0;
}