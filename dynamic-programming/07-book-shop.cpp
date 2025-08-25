/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 5;
int cts[1001], wts[1001], dp[100001];

void solve() {
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; ++i) cin >> wts[i];
    for (int i = 0; i < N; ++i) cin >> cts[i];

    // dp[i] -> what is the maximum cost we can get at index `i`

    for (int i = 0; i < N; ++i) {
        for (int wt = W; wt >= wts[i]; --wt) {
            dp[wt] = max(dp[wt], dp[wt - wts[i]] + cts[i]);
        }
    }

    cout << dp[W];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}