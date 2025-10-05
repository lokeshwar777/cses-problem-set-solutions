/* 777 */
#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> vec(K);
    for (int i = 0; i < K; ++i) cin >> vec[i];
    for (int i = 1; i <= N; ++i) {
        for (int x : vec) {
            if (i - x >= 0) dp[i] |= !dp[i - x];
        }
        cout << (dp[i] ? 'W' : 'L');
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}