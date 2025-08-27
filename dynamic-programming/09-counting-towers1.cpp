/* 777 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAX_N = 1e6;
int N, dp[MAX_N + 1][2];

int32_t main() {
    dp[1][0] = dp[1][1] = 1;  // base case
    for (int i = 2; i <= MAX_N; ++i) {
        dp[i][1] = ((4LL * dp[i - 1][1]) % MOD + dp[i - 1][0]) % MOD;
        dp[i][0] = ((2LL * dp[i - 1][0]) % MOD + dp[i - 1][1]) % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (dp[N][1] + dp[N][0]) % MOD << '\n';
    }
}