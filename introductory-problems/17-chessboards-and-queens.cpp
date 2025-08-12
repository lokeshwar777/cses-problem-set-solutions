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
int available[8][8];
int res = 0;

void pre() {}

void rec(int row = 0, int cols_msk = 0, int diags_msk = 0,
         int anti_diags_msk = 0) {
    if (row == n) {
        ++res;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!available[row][col] || ((cols_msk >> col) & 1) ||
            ((diags_msk >> (row + col)) & 1) ||
            ((anti_diags_msk >> (row - col + 7)) & 1))
            continue;
        rec(row + 1, cols_msk | (1 << col), diags_msk | (1 << (row + col)),
            anti_diags_msk | (1 << (row - col + 7)));
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

    rec();

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}