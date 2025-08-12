/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
// using vi = vector <int>;
// using vii = vector <vi>;
// using viii = vector <vii>;
// using pii = pair<int,int>;
// using vpii = vector<pii>;

// vpii dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};
const int rows = 9, cols = 9, maxSteps = 48;
int arr[maxSteps];
int vis[rows][cols];

void pre() {}

int rec(int steps, int row, int col) {
    // pruning
    if (vis[row - 1][col] && vis[row + 1][col] && !vis[row][col - 1] &&
        !vis[row][col + 1])
        return 0;
    if (!vis[row - 1][col] && !vis[row + 1][col] && vis[row][col - 1] &&
        vis[row][col + 1])
        return 0;

    // base case
    if ((row == (rows - 2)) && (col == 1)) {
        return steps == maxSteps;
    }
    if (steps == maxSteps) {
        return 0;
    }

    vis[row][col] = 1;

    int cnt = 0;
    if (arr[steps] < 4) {  // forced
        int dx = dirx[arr[steps]], dy = diry[arr[steps]];
        if (!vis[row + dx][col + dy]) cnt += rec(steps + 1, row + dx, col + dy);
    } else {
        for (int i = 0; i < 4; ++i) {
            int dx = dirx[i], dy = diry[i];
            if (!vis[row + dx][col + dy])
                cnt += rec(steps + 1, row + dx, col + dy);
        }
    }

    vis[row][col] = 0;

    return cnt;
}

void print2d() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            cout << vis[row][col] << " ";
        }
        cout << endl;
    }
}

void charToInt(string s) {
    for (int i = 0; i < maxSteps; ++i) {
        switch (s[i]) {
            case 'U':
                arr[i] = 0;
                break;
            case 'R':
                arr[i] = 1;
                break;
            case 'D':
                arr[i] = 2;
                break;
            case 'L':
                arr[i] = 3;
                break;
            default:
                arr[i] = 4;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    for (int row = 0; row < rows; ++row) vis[row][0] = vis[row][cols - 1] = 1;
    for (int col = 0; col < cols; ++col) vis[0][col] = vis[rows - 1][col] = 1;
    // print2d();
    charToInt(s);
    // for (auto &x : arr) cout << x << " ";
    int res = rec(0, 1, 1);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre();
    solve();
}