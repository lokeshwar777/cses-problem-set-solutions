/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int n, q;
    cin >> n >> q;
    vec.resize(n);
    for (auto &x : vec) cin >> x;
    vector<int> prefix_sum = {0};
    for (auto &x : vec) prefix_sum.push_back(prefix_sum.back() + x);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}