/* 777 */

#include <bits/stdc++.h>
using namespace std;
// # define int long long

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int R, C;
int grid[1010][1010], vis[1010][1010];

bool notValid(int r, int c) {
    return r < 0 || c < 0 || r == R || c == C || vis[r][c] || grid[r][c];
}

void dfs(int r, int c) {
    if (notValid(r, c)) return;
    vis[r][c] = 1;
    for (int i = 0; i < 4; ++i) {
        dfs(r + dr[i], c + dc[i]);
    }
}

void solve() {
    char x;
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> x;
            grid[r][c] = x == '#';
        }
    }
    int cnt = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (notValid(r, c)) continue;
            dfs(r, c);
            ++cnt;
        }
    }
    cout << cnt << "\n";
}

signed main() {
    solve();
    return 0;
}