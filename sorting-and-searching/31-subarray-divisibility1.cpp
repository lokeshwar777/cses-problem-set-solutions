/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
int MOD = 1e9 + 7;

int mod(int x) {
    return ((x % MOD) + MOD) % MOD;
}
int add(int a, int b) {
    return (mod(a) + mod(b)) % MOD;
}
int mul(int a, int b) {
    return mod((a * b) % MOD);
}

void solve() {
    int n;
    cin >> n;
    MOD = n;
    map<int, int> mp;
    mp[0] = 1;
    int x, cnt = 0, presum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        presum = add(presum, x);
        cnt += mp[presum];
        mp[presum] += 1;
        // cout << x << " " << presum << " " << cnt << endl;
    }
    cout << cnt;
}

int32_t main() {
    FAST_IO
    int testcases = 1;
    // cin >> testcases;
    while (testcases--) solve();
    return 0;
}