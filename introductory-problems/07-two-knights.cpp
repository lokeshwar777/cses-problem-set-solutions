/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x = (i * i * ((i * i) - 1)) / 2;
        x -= 4 * (i - 1) * (i - 2);
        cout << x << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}