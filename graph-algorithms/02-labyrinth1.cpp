/* 777 */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define print_grid(grid)                    \
    for (auto &x : grid) {                  \
        for (auto &y : x) cout << y << " "; \
        cout << endl;                       \
    }

const int INF = 1e9;
int dirr[4] = {-1, 0, 1, 0};
int dirc[4] = {0, 1, 0, -1};
char dirMap[4] = {'U', 'R', 'D', 'L'};

int R, C, dr, dc;
int grid[1010][1010], vis[1010][1010];
// vector<vector<int>> grid, vis;
pair<int, int> par[1010][1010];

bool notValid(int r, int c) {
    return r < 0 || c < 0 || r == R || c == C || vis[r][c] || grid[r][c];
}

int bfs(int sr, int sc) {
    int res = 0;
    queue<pair<int, pair<int, int>>> q;
    vis[sr][sc] = 1;
    q.push({0, {sr, sc}});
    while (!q.empty()) {
        auto [cur, cell] = q.front();
        auto [r, c] = cell;
        q.pop();
        if (r == dr && c == dc) {
            return cur;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirr[i], nc = c + dirc[i];
            // cout << r << " " << c << " " << nr << " " << nc << endl;
            if (notValid(nr, nc)) continue;
            vis[nr][nc] = 1;
            q.push({cur + 1, {nr, nc}});
            par[nr][nc] = {r, c};
        }
    }
    return INF;
}

void solve() {
    memset(grid, 0, sizeof(grid));
    memset(vis, 0, sizeof(vis));
    int sr, sc;
    char x;
    cin >> R >> C;
    // grid.resize(R + 1, vector(C + 1, 0));
    // vis.resize(R + 1, vector(C + 1, 0));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> x;
            if (x == 'A') {
                sr = r;
                sc = c;
            } else if (x == 'B') {
                dr = r;
                dc = c;
            } else
                grid[r][c] = x == '#';
        }
    }
    int ans = bfs(sr, sc);
    if (ans == INF) {
        cout << "NO" << "\n";
        return;
    }
    string path;
    for (int r = dr, c = dc; make_pair(r, c) != make_pair(sr, sc);) {
        auto [nr, nc] = par[r][c];
        for (int i = 0; i < 4; ++i) {
            if (r == (nr + dirr[i]) && c == (nc + dirc[i])) {
                path.push_back(dirMap[i]);
            }
        }
        r = nr;
        c = nc;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << "\n" << ans << "\n" << path << "\n";
}

signed main() {
    solve();
    return 0;
}