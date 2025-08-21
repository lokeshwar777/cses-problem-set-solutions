/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;
const int N = 1e6;
int dp[N + 1], arr[101];

void pre() {}

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    dp[0] = 1;
    for (int sum = 1; sum <= x; ++sum) {
        for (int i = 0; i < n; ++i) {
            if (sum >= arr[i]) dp[sum] = (dp[sum] + dp[sum - arr[i]]) % MOD;
        }
    }
    cout << dp[x];
}

int32_t main() {
    FAST_IO
    pre();
    solve();
}