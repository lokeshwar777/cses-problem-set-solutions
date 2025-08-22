/* 777 */

// PULL DP (backward)

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int MOD = 1e9 + 7;
int add(int a, int b) {
    return (a + b) % MOD;
}

// int dp[110][1000010];
int dp[1000010];

int n, target_sum;
vector<int> vec;

/* top down
// form 1
int rec(int level, int rem_sum) {
    if (rem_sum == 0) return 1;
    if (level == n) return 0;
    int cnt = rec(level + 1, rem_sum);
    if (vec[level] <= rem_sum) cnt = add(cnt, rec(level, rem_sum - vec[level]));
    return cnt;
}

void solve() {
    cin >> n >> target_sum;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    int res = rec(0, target_sum);
    cout << res << '\n';
}
*/

/* bottom up
void solve() {
    cin >> n >> target_sum;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    dp[n][0] = 1;
    for (int level = n - 1 ; level >= 0 ; --level) {
        dp[level][0] = 1;
        for (int rem_sum = 1 ; rem_sum <= target_sum ; ++rem_sum) {
            dp[level][rem_sum] = dp[level + 1][rem_sum];
            if (vec[level] <= rem_sum) dp[level][rem_sum] =
add(dp[level][rem_sum], dp[level][rem_sum - vec[level]]);
        }
    }
    cout << dp[0][target_sum];
}
*/

void solve() {
    cin >> n >> target_sum;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    dp[0] = 1;
    for (int level = n - 1; level >= 0; --level) {
        for (int rem_sum = vec[level]; rem_sum <= target_sum; ++rem_sum) {
            dp[rem_sum] = add(dp[rem_sum], dp[rem_sum - vec[level]]);
        }
    }
    cout << dp[target_sum];
}

int32_t main() {
    FAST_IO
    solve();
}