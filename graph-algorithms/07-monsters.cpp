/* 777 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r, c, i;
    Node(int row = -1, int col = -1, int index = -1)
        : r(row), c(col), i(index) {};
};

// up, down, left, right
char dirp[4] = {'U', 'D', 'L', 'R'};
int dirr[4] = {-1, 1, 0, 0};
int dirc[4] = {0, 0, -1, 1};
const int MAX_N = 1005, D = 4;
int R, C, SR, SC, DR, DC, grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
Node par[MAX_N][MAX_N];
queue<Node> q;  // Node.index = type (monster/human) only for queue

int multi_source_bfs(int sr = SR, int sc = SC) {
    q.push(Node(sr, sc, 1));
    vis[sr][sc] = 1;
    int lvl = 0;
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node x = q.front();
            int r = x.r, c = x.c, ty = x.i;
            if (ty && (r == 1 || r == R || c == 1 || c == C)) {
                DR = r;
                DC = c;
                return lvl;
            }
            q.pop();
            for (int i = 0; i < D; ++i) {
                int nr = r + dirr[i], nc = c + dirc[i];
                if (vis[nr][nc] || grid[nr][nc]) continue;
                vis[nr][nc] = 1;
                q.push(Node(nr, nc, ty));
                if (ty) par[nr][nc] = Node(r, c, i);
            }
        }
        lvl++;
    }
    return -1;
}

string get_path(int sr = SR, int sc = SC, int dr = DR, int dc = DC) {
    string path;
    for (int r = dr, c = dc; r != sr || c != sc;) {
        Node nxt = par[r][c];
        r = nxt.r;
        c = nxt.c;
        path.push_back(dirp[nxt.i]);
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
            grid[r][c] = x == '#';
            if (x == 'A') {
                SR = r;
                SC = c;
            } else if (x == 'M') {
                q.push(Node(r, c, 0));
                vis[r][c] = 1;
            }
        }
    }
    for (int r = 0; r <= R + 1; ++r) vis[r][0] = vis[r][C + 1] = 1;
    for (int c = 0; c <= C + 1; ++c) vis[0][c] = vis[R + 1][c] = 1;
    int len = multi_source_bfs();
    if (len < 0) {
        cout << "NO";
        return;
    }
    string path = get_path();
    cout << "YES\n" << (int) path.size() << '\n';
    cout << get_path();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}