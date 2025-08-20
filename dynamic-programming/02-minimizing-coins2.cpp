/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortfn(x, fn) sort(all(x), fn)
#define sortr(x) sort(all(x), greater<int>())

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using vpii = vector<pii>;

const int inf = INT_MAX;

int res = 0, n;
vi coins;
int dp[2][1000010];

void pre() {
    memset(dp, -1, sizeof(dp));
}

int topDown(int level, int sum_left) {
    // pruning
    if (sum_left == 0) return 0;

    // base case
    if (level == n || coins[level] > sum_left) return inf;

    // cache check
    if (dp[level][sum_left] != -1) return dp[level][sum_left];

    // transitions
    int ans = topDown(level + 1, sum_left);
    ans = min(ans, 1 + topDown(level, sum_left - coins[level]));

    // save and return
    return dp[level][sum_left] = ans;
}

int bottomUp(int target_sum) {
    // base case
    for (int sum_left = 1; sum_left <= target_sum; sum_left++)
        dp[n & 1][sum_left] = inf;

    for (int level = n - 1; level >= 0; level--) {
        for (int sum_left = 1; sum_left < coins[level]; sum_left++)
            dp[level & 1][sum_left] = inf;
        for (int sum_left = coins[level]; sum_left <= target_sum; sum_left++) {
            int ans = dp[(level + 1) & 1][sum_left];
            ans = min(ans, 1 + dp[level & 1][sum_left - coins[level]]);
            dp[level & 1][sum_left] = ans;
            // cout << level << " " << sum_left << " " << ans << endl;
        }
    }

    return dp[0][target_sum];
}

void solve() {
    int k;
    cin >> n >> k;
    coins.resize(n);
    for (auto &x : coins) cin >> x;
    sortf(coins);
    // res = topDown(0, k);
    res = bottomUp(k);
    if (res == inf) res = -1;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre();
    solve();
}