/* 777 */
#include "bits/stdc++.h"
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

vector<vector<int>> dp, grid;

int bottomUp(int r, int c) {
    dp[r - 1][c - 1] = grid[r - 1][c - 1];
    for (int row = r - 1; row >= 0; row--) {
        for (int col = c - 1; col >= 0; col--) {
            if (!grid[row][col]) continue;
            dp[row][col] += dp[row + 1][col] + dp[row][col + 1];
            dp[row][col] %= MOD;
        }
    }
    return dp[0][0];
}

void solve() {
    int r, c;
    cin >> r;
    c = r;
    dp.resize(r + 1, vector<int>(c + 1, 0));
    grid.resize(r, vector<int>(c));
    for (int row = 0; row < r; ++row) {
        for (int col = 0; col < c; ++col) {
            char x;
            cin >> x;
            grid[row][col] = (x != '*');
        }
    }
    int res = bottomUp(r, c);
    cout << res << "\n";
    // for (auto &x: dp) {
    //   for (auto &y:x) cout << y << " ";cout << endl;
    // }
}

signed main() {
    solve();
    return 0;
}