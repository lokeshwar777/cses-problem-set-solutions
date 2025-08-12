/* 777 */
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// #define int long long
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second
#define bitcount __builtin_popcount
#define bitcountll __builtin_popcountll

#define endl '\n'
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (int) (x).size()

#define MAXV(x) *max_element(ALL(x))
#define MINV(x) *min_element(ALL(x))
#define SUMLL(x) accumulate(ALL(x), 0LL)
#define SORTA(x) sort(ALL(x))
#define SORTFn(x, fn) sort(ALL(x), fn)
#define SORTD(x) sort(ALL(x), greater<int>())

#define debug(x) cerr << #x << " = " << x << endl;
#define PRINTVec(arr)                         \
    {                                         \
        for (auto& x : arr) cout << x << " "; \
        cout << '\n';                         \
    }
#define PRINTGrid(grid)                       \
    {                                         \
        for (auto& row : grid) PRINTVec(row); \
    }
template <typename... Args>
void PRINTArgs(Args&&... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

using VI = vector<int>;
using VII = vector<VI>;
using VIII = vector<VII>;
using PII = pair<int, int>;
using VPII = vector<PII>;

const int INF = 1e9;
const long long INF_LL = 1e18;
const int MOD = 1e9 + 7;
// const double PI = 3.14159265358979323846;
// const int dr[4] = {-1, 0, 1, 0};
// const int dc[4] = {0, 1, 0, -1};
const int dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int add(int a, int b) {
    return (a + b) % MOD;
}
int mul(int a, int b) {
    return (a * b) % MOD;
}

int R, C;
VII grid;

void bfs01() {
    queue<pair<int, PII>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        int dist = q.front().F;
        auto [r, c] = q.front().S;
        q.pop();
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != -1) continue;
        grid[r][c] = dist;
        for (int i = 0; i < 8; ++i) q.push({dist + 1, {r + dr[i], c + dc[i]}});
    }
}

void solve() {
    int n;
    cin >> n;
    R = C = n;
    grid.resize(n, VI(n, -1));
    bfs01();
    PRINTGrid(grid);
    cout << endl;
}

int32_t main() {
    FAST_IO
    int testcases = 1;
    // cin >> testcases;
    while (testcases--) solve();
    return 0;
}