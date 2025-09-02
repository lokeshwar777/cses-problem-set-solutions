/* 777 */
#include <bits/stdc++.h>
using namespace std;

// TC: O(N * logN), SC: O(length of LIS)
int N, x;

// LIS(longest increasing subsequence)
// dp(i) -> length of LIS ending at index `i`

void solve() {
    cin >> N;
    vector<int> lis;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        int lb = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if (lb == (int) lis.size()) {
            lis.push_back(x);
        } else {
            lis[lb] = x;
        }
    }
    cout << (int) lis.size();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

// TC: O(N * N), SC: O(N)
/*
int N, arr[200010], dp[200010], ans = 1;

// LIS(longest increasing subsequence)
// dp(i) -> length of LIS ending at index `i`

void solve() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]) dp[i] = max(dp[i], 1 + dp[j]);
            ans = max(ans, dp[i]);
        }
    }
    // cout << *max_element(dp[1].begin(), dp[1].end());
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
*/

// TC: O(N * N), SC: O(N * N)
/*
int N, arr[200010], ans = 1;  // mistake : min possible ans is 1 not 0
vector<vector<int>> dp;

// LIS(longest increasing subsequence)
// dp(i, j) -> length of LIS at index `i` with `arr[j]` as prev value

void solve() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    dp.resize(N + 2, vector<int>(N + 2, 1));  // mistake : the min length LIS is
1 not 0 for (int i = N; i > 0; --i) { for (int j = 1; j < i; ++j) {  // mistake
: j <= N is wrong dp[i][j] = dp[i + 1][j]; if (arr[j] < arr[i]) dp[i][j] =
max(dp[i][j], 1 + dp[i + 1][i]); ans = max(ans, dp[i][j]);
        }
    }
    // cout << *max_element(dp[1].begin(), dp[1].end());
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
*/