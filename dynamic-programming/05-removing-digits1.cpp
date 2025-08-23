/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 5;
const int SIZE = 1e6 + 5;
int dp[SIZE];

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) dp[i] = INF;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j; j /= 10) {
            dp[i] = min(dp[i], dp[i - (j % 10)] + 1);
        }
    }
    cout << dp[N];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}