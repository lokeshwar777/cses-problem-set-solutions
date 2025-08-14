/* 777 */
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#define int long long

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<string> inp(N);
    for (int i = 0; i < N; ++i) cin >> inp[i];

    // prefix computation
    vector<vector<int>> pref(N, vector<int>(N, 0));
    for (int row = 0; row < N; ++row) {
        int col_prefix = 0;
        for (int col = 0; col < N; ++col) {
            col_prefix += inp[row][col] == '*';
            pref[row][col] = col_prefix;
            if (row) pref[row][col] += pref[row - 1][col];
        }
    }

    for (int q = 0; q < Q; ++q) {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        int max_row = max(row1, row2), max_col = max(col1, col2);
        int min_row = min(row1, row2) - 1, min_col = min(col1, col2) - 1;
        int cur = pref[max_row - 1][max_col - 1];
        if (min_col) cur -= pref[max_row - 1][min_col - 1];
        if (min_row) cur -= pref[min_row - 1][max_col - 1];
        if (min_row && min_col) cur += pref[min_row - 1][min_col - 1];
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