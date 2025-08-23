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

int n, dp[1000010];
/*
int rec(int num) {
    if (dp[num] != -1) return dp[num];
    int cnt = INF;
    for (int cur = num ; cur > 0 ; cur /= 10) {
        if (!(cur % 10)) continue;
        cnt = min(cnt, 1 + rec(num - (cur % 10)));
    }
    return dp[num] = (cnt == INF) ? 0 : cnt;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    int res = rec(n);
    cout << res;
}
*/

void solve() {
    cin >> n;
    for (int num = 1; num <= n; ++num) {
        dp[num] = INF;
        for (int cur = num; cur > 0; cur /= 10) {
            if (!(cur % 10)) continue;
            dp[num] = min(dp[num], 1 + dp[num - (cur % 10)]);
        }
    }
    cout << dp[n];
}

int32_t main() {
    FAST_IO
    solve();
}