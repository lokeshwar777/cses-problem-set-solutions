/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 5;
const int N = 500;
int dp[N + 1][N + 1];

// dp(i, j) -> min no. of moves to convert a ixj rectangle into squares

void pre() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = (i == j) ? 0 : INF;
            if (i == j) continue;
            for (int k = 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);  // fix i
            }
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);  // fix j
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int i, j;
    cin >> i >> j;
    cout << dp[i][j];
}