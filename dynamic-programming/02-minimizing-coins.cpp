/* 777 */

// PUSH DP (forward)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 7;
const int SIZE = 1e6 + 5;
int dp[SIZE];

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> vec(N);
    for (int &x : vec) cin >> x;
    for (int x = 1; x <= X; ++x) dp[x] = INF;
    dp[0] = 0;
    for (int x = 0; x < X; ++x) {
        for (int num : vec) {
            if (x + num > X) continue;
            dp[x + num] = min(dp[x + num], dp[x] + 1);
        }
    }
    if (dp[X] == INF) dp[X] = -1;
    cout << dp[X];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}