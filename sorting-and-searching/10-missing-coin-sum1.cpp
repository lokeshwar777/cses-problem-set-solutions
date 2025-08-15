/* 777 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int presum = 0;
    for (auto &x : v) {
        if (presum + 1 < x) break;
        presum += x;
    }
    cout << (presum + 1) << '\n';
}

signed main() {
    solve();
    return 0;
}