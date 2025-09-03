/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, arr[5010], dp[5010][5010];

int rec(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int flag = N - (r - l);
    int a = arr[l] * (flag & 1) - rec(l + 1, r);
    int b = arr[r] * (flag & 1) - rec(l, r - 1);
    return dp[l][r] = max(a, b);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // recursive
    // memset(dp, -1, sizeof(dp));
    // cout << rec(0, N - 1);

    for (int r = 0; r < N; ++r) {
        for (int l = r; l >= 0; --l) {
            int flag = N - (r - l);
            int first = arr[l] * (flag & 1) - ((l < N - 1) ? dp[l + 1][r] : 0);
            int last = arr[r] * (flag & 1) - ((r > 0) ? dp[l][r - 1] : 0);
            dp[l][r] = max(first, last);
        }
    }
    cout << dp[0][N - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}