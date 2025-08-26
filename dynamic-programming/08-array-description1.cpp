/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int SIZE = 1e5 + 5;

int N, M, arr[SIZE], dp[100001][101];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // base case
    for (int m = 1; m <= M; ++m) dp[N][m] = 1;

    for (int i = N - 1; i > 0; --i) {
        for (int prev = 1; prev <= M; ++prev) {
            if (arr[i] && abs(prev - arr[i]) > 1) continue;
            int cnt = 0;
            if (arr[i])
                cnt = dp[i + 1][arr[i]];
            else {
                cnt = dp[i + 1][prev - 1] + dp[i + 1][prev + 1];
                if (cnt >= MOD) cnt %= MOD;
                cnt += dp[i + 1][prev];
                if (cnt >= MOD) cnt %= MOD;
            }
            dp[i][prev] = cnt;
        }
    }

    int cnt = 0;
    if (arr[0]) {
        cnt = dp[1][arr[0]];
    } else {
        for (int m = 1; m <= M; ++m) {
            cnt += dp[1][m];
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