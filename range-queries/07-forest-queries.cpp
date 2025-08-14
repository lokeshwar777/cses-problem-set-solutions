/* 777 */
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#define int long long

void solve() {
    int N, Q;
    cin >> N >> Q;
    string row_string;
    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));
    for (int row = 0; row < N; ++row) {
        cin >> row_string;
        for (int col = 0; col < N; ++col) {
            prefix_sum[row + 1][col + 1] =
                prefix_sum[row + 1][col] + prefix_sum[row][col + 1] -
                prefix_sum[row][col] + (row_string[col] == '*');
        }
    }

    for (int q = 0; q < Q; ++q) {
        int min_row, min_col, max_row, max_col;
        cin >> min_row >> min_col >> max_row >> max_col;
        min_row--;
        min_col--;
        int cur = prefix_sum[max_row][max_col] - prefix_sum[max_row][min_col] -
                  prefix_sum[min_row][max_col] + prefix_sum[min_row][min_col];
        cout << cur << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
