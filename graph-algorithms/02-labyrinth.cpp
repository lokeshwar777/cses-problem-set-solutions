/* 777 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r;
    int c;
    int i;
    Node(int rr, int cc, int ii) : r(rr), c(cc), i(ii) {};
};

// up, down, left, right
char dirp[4] = {'U', 'D', 'L', 'R'};
int dirr[4] = {-1, 1, 0, 0};
int dirc[4] = {0, 0, -1, 1};
const int MAX_N = 1005, D = 4;
int R, C, SR, SC, DR, DC;
bool vis[MAX_N][MAX_N];
Node *par[MAX_N][MAX_N];

int bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.emplace(sr, sc);
    vis[sr][sc] = 1;
    int lvl = 0;
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            auto [r, c] = q.front();
            q.pop();
            if (r == DR && c == DC) return lvl;
            for (int i = 0; i < D; ++i) {
                int nr = r + dirr[i], nc = c + dirc[i];
                if (vis[nr][nc]) continue;
                vis[nr][nc] = 1;
                q.emplace(nr, nc);
                par[nr][nc] = new Node(r, c, i);
            }
        }
        lvl++;
    }
    return -1;
}

string get_path(int sr, int sc, int dr, int dc) {
    string path;
    for (int r = sr, c = sc; r != dr || c != dc;) {
        Node *nxt = par[r][c];
        r = nxt->r;
        c = nxt->c;
        path.push_back(dirp[nxt->i]);
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    cin >> R >> C;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            char x;
            cin >> x;
            vis[r][c] = x == '#';
            if (x == 'A') {
                SR = r;
                SC = c;
            } else if (x == 'B') {
                DR = r;
                DC = c;
            }
        }
    }
    for (int r = 0; r <= R + 1; ++r) vis[r][0] = vis[r][C + 1] = 1;
    for (int c = 0; c <= C + 1; ++c) vis[0][c] = vis[R + 1][c] = 1;

    int ans = bfs(SR, SC);
    if (ans < 0)
        cout << "NO";
    else {
        string path = get_path(DR, DC, SR, SC);
        cout << "YES\n" << ans << "\n" << path;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}