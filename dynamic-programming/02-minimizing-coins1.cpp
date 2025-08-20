/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = 1e9;
const int MOD = 1e9 + 7;

int mod(int x) {
    return ((x % MOD) + MOD) % MOD;
}
int add(int a, int b) {
    return (mod(a) + mod(b)) % MOD;
}

const int N = 1e6;
int dp[N + 1], arr[101];

void pre() {}

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int sum = 1; sum <= x; ++sum) {
        dp[sum] = INF;
        for (int i = 0; i < n; ++i) {
            if (sum >= arr[i]) dp[sum] = min(dp[sum], add(1, dp[sum - arr[i]]));
        }
    }

    if (dp[x] == INF) dp[x] = -1;
    cout << dp[x];
}

int32_t main() {
    FAST_IO
    pre();
    solve();
}