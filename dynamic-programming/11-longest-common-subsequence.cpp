/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
int A, B, a[1010], b[1010], dp[1010][1010];

void solve() {
    cin >> A >> B;
    for (int i = 0; i < A; ++i) cin >> a[i];
    for (int i = 0; i < B; ++i) cin >> b[i];
    for (int i = A - 1; i >= 0; --i) {
        for (int j = B - 1; j >= 0; --j) {
            dp[i][j] = (a[i] == b[j]) ? (1 + dp[i + 1][j + 1])
                                      : max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << '\n';
    vector<int> lcs;
    for (int i = 0, j = 0; i < A && j < B;) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
            ++i;
            ++j;
        } else if (dp[i + 1][j] > dp[i][j + 1]) {
            ++i;
        } else {
            ++j;
        }
    }
    for (int x : lcs) cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

// visualise
// for (int i = 0; i <= A; ++i) {
//     for (int j = 0; j <= B; ++j) {
//         cout << dp[i][j] << " ";
//     }
//     cout << endl;
// }