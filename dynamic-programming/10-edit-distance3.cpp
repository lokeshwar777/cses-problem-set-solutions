/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;
int n, m;
int dp[5001][5001];
string a, b;

int rec(int i, int j) {
    if (j == m) return n - i;
    if (i == n) return m - j;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = (a[i] != b[j]) + rec(i + 1, j + 1);  // edit
    ans = min(ans, 1 + rec(i + 1, j));             // remove
    ans = min(ans, 1 + rec(i, j + 1));             // add
    // cout << i << " " << j << " " << ans << endl;
    return dp[i][j] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    n = a.size();
    m = b.size();
    int res = rec(0, 0);
    cout << res;
}

int32_t main() {
    FAST_IO
    solve();
}