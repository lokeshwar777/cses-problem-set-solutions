/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n, k;
// int dp[1001][100001], arr[1001], cost[1001];
int dp[2][100001], arr[1001], cost[1001];

/*
int rec(int level, int rem) {
    if (level == n) return 0;
    int tot = rec(level + 1, rem);
    if (arr[level] <= rem) tot = max(tot, cost[level] + rec(level + 1, rem -
arr[level])); return tot;
}
*/

/*
void solve() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; ++i) cin >> arr[i];
    for (int i = 0 ; i < n ; ++i) cin >> cost[i];
    // cout << rec(0, k);

    for (int level = n - 1 ; level >= 0 ; level--) {
        for (int rem = 0 ; rem <= k ; rem++) {
            dp[level][rem] = dp[level + 1][rem];
            if (arr[level] <= rem) {
                dp[level][rem] = max(dp[level][rem], cost[level] + dp[level +
1][rem  - arr[level]]);
            }
        }
    }

    cout << dp[0][k];
}
*/

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];
    // cout << rec(0, k);

    for (int level = n - 1; level >= 0; level--) {
        for (int rem = 0; rem <= k; rem++) {
            dp[level & 1][rem] = dp[(level + 1) & 1][rem];
            if (arr[level] <= rem) {
                dp[level & 1][rem] =
                    max(dp[level & 1][rem],
                        cost[level] + dp[(level + 1) & 1][rem - arr[level]]);
            }
        }
    }

    cout << dp[0][k];
}

int32_t main() {
    FAST_IO
    solve();
}