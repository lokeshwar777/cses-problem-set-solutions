/* 777 */
#include <bits/stdc++.h>
using namespace std;

using VC = vector<char>;
using VCC = vector<VC>;
#define PRINTVec(arr)                  \
    {                                  \
        for (auto& x : arr) cout << x; \
        cout << '\n';                  \
    }
#define PRINTGrid(grid)                       \
    {                                         \
        for (auto& row : grid) PRINTVec(row); \
    }

int R, C;
VCC grid;
bool possible = 1;
char ltrs[4] = {'A', 'B', 'C', 'D'};

void rec(int r, int c) {
    if (r == R) return;
    if (c == C) {
        rec(r + 1, 0);
        return;
    }
    set<char> st = {grid[r][c]};
    if (r) st.insert(grid[r - 1][c]);
    if (c) st.insert(grid[r][c - 1]);
    for (auto& ltr : ltrs)
        if (!st.count(ltr)) {
            grid[r][c] = ltr;
            rec(r, c + 1);
            return;
        }
    possible = 0;
}

int main() {
    cin >> R >> C;
    grid.resize(R, VC(C));
    for (auto& row : grid)
        for (auto& x : row) cin >> x;
    rec(0, 0);
    if (possible) PRINTGrid(grid) else cout << "IMPOSSIBLE";
    return 0;
}
