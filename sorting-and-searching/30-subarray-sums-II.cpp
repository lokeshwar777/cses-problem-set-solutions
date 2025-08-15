/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    mp[0] = 1;
    int x, cnt = 0, presum = 0;
    while (n--) {
        cin >> x;
        presum += x;
        cnt += mp[presum - k];
        mp[presum] += 1;
    }
    cout << cnt;
}

int32_t main() {
    FAST_IO
    solve();
}