/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int SIZE = 1e5 + 5;

int N, M, arr[SIZE], dp[100001][101];

// 1e5 * 100
int rec(int i, int prev) {
    if (prev < 1 || prev > M) return 0;
    if (i == N) return 1;
    if (arr[i] && abs(prev - arr[i]) > 1) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];
    int cnt = 0;
    if (arr[i]) {
        cnt = rec(i + 1, arr[i]);
    } else {
        cnt = rec(i + 1, prev - 1) + rec(i + 1, prev + 1);
        if (cnt >= MOD) cnt %= MOD;
        cnt += rec(i + 1, prev);
        if (cnt >= MOD) cnt %= MOD;
    }
    return dp[i][prev] = cnt;
}

void solve() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int cnt = 0;
    if (arr[0]) {
        cnt = rec(1, arr[0]);
    } else {
        for (int m = 1; m <= M; ++m) {
            cnt += rec(1, m);
            if (cnt >= MOD) cnt %= MOD;
        }
    }
    cout << cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}