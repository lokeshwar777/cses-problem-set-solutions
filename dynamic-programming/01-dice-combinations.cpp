/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = INT_MAX;
const int MOD = 1e9 + 7;

int mod(int x) {
    return ((x % MOD) + MOD) % MOD;
}
int add(int a, int b) {
    return (mod(a) + mod(b)) % MOD;
}

const int N = 1e6;
int dp[N + 1], arr[N + 1];

void solve() {
    int n;
    cin >> n;
    dp[0] = 1;  // base case
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, 6); ++j) dp[i] = add(dp[i], dp[i - j]);
    }
    cout << dp[n];
}

int32_t main() {
    FAST_IO
    solve();
}
