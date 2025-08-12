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
int queens[8];
int board[8][8];

void pre() {}

bool is_valid() {
    for (int x1 = 0; x1 < 8; ++x1) {
        for (int x2 = x1 + 1; x2 < 8; ++x2) {
            int y1 = queens[x1], y2 = queens[x2];
            if (y1 == y2 || (abs(x1 - x2) == abs(y1 - y2))) return 0;
        }
    }
    return 1;
}

int n_queens(int level) {
    if (level == 8) return is_valid();
    int count = 0;
    for (int col = 0; col < 8; ++col) {
        if (!board[level][col]) continue;
        queens[level] = col;
        count += n_queens(level + 1);
    }
    return count;
}

void solve() {
    // cin>>n;
    n = 8;
    char c;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> c;
            board[i][j] = (c == '.');
        }
    }
    int res = n_queens(0);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}