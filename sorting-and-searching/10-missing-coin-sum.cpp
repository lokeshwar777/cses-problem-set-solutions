/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec) cin >> x;
    int req = 1;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n && vec[i] <= req; ++i) req += vec[i];
    cout << req;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}