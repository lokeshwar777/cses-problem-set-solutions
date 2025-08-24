/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int SIZE = 1005;
int dp[SIZE][SIZE];

void solve() {
    int N;
    cin >> N;
    dp[0][1] = 1;  // or dp[1][0] = 1;
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            char x;
            cin >> x;
            if (x == '.') {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                if (dp[r][c] >= MOD) dp[r][c] -= MOD;
            }
        }
    }
    cout << dp[N][N];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}