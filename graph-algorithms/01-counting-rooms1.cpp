/* 777 */
#include <bits/stdc++.h>
using namespace std;

// up, down, left, right
int DR[4] = {-1, 1, 0, 0};
int DC[4] = {0, 0, -1, 1};
const int MAX_N = 1005, D = 4;
int R, C;
bool vis[MAX_N][MAX_N];

void dfs(int r, int c) {
    if (vis[r][c]) return;
    vis[r][c] = 1;
    for (int i = 0; i < D; ++i) {
        dfs(r + DR[i], c + DC[i]);
    }
}

void bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.emplace(sr, sc);
    vis[sr][sc] = 1;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < D; ++i) {
            int nr = r + DR[i], nc = c + DC[i];
            if (vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            q.emplace(nr, nc);
        }
    }
}

int conn_cmpts(int sr, int sc) {
    int cnt = 0;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (vis[r][c]) continue;
            cnt++;
            // dfs(r, c);
            bfs(r, c);
        }
    }
    return cnt;
}

void solve() {
    cin >> R >> C;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            char x;
            cin >> x;
            vis[r][c] = x == '#';
        }
    }
    for (int r = 0; r <= R + 1; ++r) vis[r][0] = vis[r][C + 1] = 1;
    for (int c = 0; c <= C + 1; ++c) vis[0][c] = vis[R + 1][c] = 1;

    int cmpts = conn_cmpts(1, 1);
    cout << cmpts;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}