/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
int A, B, dp[5010][5010];
string a, b;

int rec(int i, int j) {
    if (i == A) return B - j;
    if (j == B) return A - i;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    int replace = (a[i] != b[j]) + rec(i + 1, j + 1);
    int addOrRemove = 1 + min(rec(i + 1, j), rec(i, j + 1));  // add or remove
    return ans = min(replace, addOrRemove);
}

void solve() {
    cin >> a >> b;
    A = a.size();
    B = b.size();

    // dp(i, j) -> min no. of ops to transform string a to b

    // recursive
    // memset(dp, -1, sizeof(dp));
    // cout << rec(0, 0);

    // base case
    for (int i = 0; i <= A; ++i) dp[i][B] = A - i;
    for (int j = 0; j <= B; ++j) dp[A][j] = B - j;

    // iterative
    for (int i = A - 1; i >= 0; --i) {
        for (int j = B - 1; j >= 0; --j) {
            dp[i][j] = INF;
            dp[i][j] =
                min(dp[i][j], (a[i] != b[j]) + dp[i + 1][j + 1]);  // replace
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);            // remove
            dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);            // add
        }
    }

    cout << dp[0][0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

// mistakes
/*
1. didn't return correcty (A - i & B - j)
2. forgot about replace
*/