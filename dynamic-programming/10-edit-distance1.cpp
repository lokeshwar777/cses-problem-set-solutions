/* 777 */

// suffix-based DP

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;
int n, m;
int dp[5001][5001];
string a, b;

void solve() {
    cin >> a >> b;
    n = a.size();
    m = b.size();

    // base case
    for (int i = 0; i < n; ++i) dp[i][m] = n - i;
    for (int j = 0; j < m; ++j) dp[n][j] = m - j;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            dp[i][j] = (a[i] != b[j]) + dp[i + 1][j + 1];  // edit
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);    // remove
            dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);    // add
        }
    }

    cout << dp[0][0];
}

int32_t main() {
    FAST_IO
    solve();
}