/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n), pse(n);
    for (int& x : vec) cin >> x;
    for (int i = 0, j = -1; i < n; ++i, j = i - 1) {
        while (j >= 0 && vec[j] >= vec[i]) j = pse[j];
        pse[i] = j;
    }
    for (int x : pse) cout << (x + 1) << ' ';
}

int32_t main() {
    FAST_IO
    solve();
}