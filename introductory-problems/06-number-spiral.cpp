/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        // - for odd, + for even
        if (i > j) {
            if ((i & 1) == 0) {
                cout << (i * i) - (j - 1) << '\n';
            } else {
                cout << (i - 1) * (i - 1) + 1 + (j - 1) << '\n';
            }
        } else {
            if (j & 1) {
                cout << j * j - (i - 1) << '\n';
            } else {
                cout << (j - 1) * (j - 1) + 1 + (i - 1) << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}