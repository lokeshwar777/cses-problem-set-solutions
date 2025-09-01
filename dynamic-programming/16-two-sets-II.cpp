/* 777 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
int N, dp[2][260000];

void solve() {
    cin >> N;
    int OFFSET = N * (N + 1) / 2;

    // odd sum not possible
    if (OFFSET & 1) {
        cout << 0;
        return;
    }

    dp[(N + 1) & 1][OFFSET] = 1;
    for (int i = N; i > 0; --i) {
        for (int s = 0; s <= 2 * OFFSET - i; ++s) {
            dp[i & 1][s] = dp[(i + 1) & 1][s + i];
        }
        for (int s = i; s <= 2 * OFFSET; ++s) {
            dp[i & 1][s] += dp[(i + 1) & 1][s - i];
            dp[i & 1][s] %= MOD;
        }
    }
    cout << (dp[1][OFFSET] * ((MOD + 1) / 2)) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}