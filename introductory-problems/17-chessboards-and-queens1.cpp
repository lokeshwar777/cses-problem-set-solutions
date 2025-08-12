/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
// const int inf=1e9;
vi vec;
// vpii vecp;
// const int N=1e6;
int n;
int cols[8], diags[15], anti_diags[15];
int available[8][8];
int res = 0;

void pre() {}

bool is_valid(int row, int col) {
    return cols[col] || diags[row + col] || anti_diags[row - col + 7];
}

void rec(int row) {
    if (row == n) {
        ++res;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!available[row][col] || is_valid(row, col)) continue;
        // cout << row << col << endl;
        cols[col] = 1;
        diags[row + col] = 1;  // row + col -> ranges from 0 to 14
        anti_diags[row - col + 7] =
            1;  // ranges from row - col -> ranges from -7 to 7
        rec(row + 1);
        cols[col] = diags[row + col] = anti_diags[row - col + 7] =
            0;  // backtrack
    }
}

void solve() {
    // cin>>n;
    n = 8;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            available[i][j] = (c == '.');
        }
    }

    rec(0);

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}