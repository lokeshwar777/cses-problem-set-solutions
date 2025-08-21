/* 777 */

// PUSH DP (forward)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 5;
int dp[SIZE];

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> vec(N);
    for (int &x : vec) cin >> x;
    dp[0] = 1;
    for (int x = 0; x < X; ++x) {
        for (int num : vec) {
            if (x + num > X) continue;
            dp[x + num] += dp[x];
            if (dp[x + num] >= MOD) {
                dp[x + num] -= MOD;
            }
        }
    }
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