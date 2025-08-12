/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int n;
    cin >> n;
    int cnt = 0, div = 5;
    while (n / div) {
        cnt += n / div;
        div *= 5;
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}