/* 777 */
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = 1e9;
const long long INF_LL = 1e18;
const int MOD = 1e9 + 7;
// const double PI = 3.14159265358979323846;

#define ll long long
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

using VI = vector<int>;
using VII = vector<VI>;
using VIII = vector<VII>;
using PII = pair<int, int>;
using VPII = vector<PII>;

#define debug(x) cerr << #x << " = " << x << endl;
#define PRINTVec(arr)                  \
    {                                  \
        EACH(x, arr) cout << x << " "; \
        cout << endl;                  \
    }
#define PRINTGrid(grid)                \
    {                                  \
        EACH(row, grid) PRINTVec(row); \
    }
template <typename... Args>
void PRINTArgs(Args&&... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

int res = 0;

void solve() {
    int n;
    cin >> n;
    VII grid(n, VI(n));
    VI v1(n, 0), v2(n, 0);
    // O(100 * 100 * (400)) ~ 4e6
    REP(r, n) {
        REP(c, n) {
            bitset<200> bs;
            REP(rr, r) bs.set(grid[rr][c]);
            REP(cc, c) bs.set(grid[r][cc]);
            REP(i, n << 1) if (!bs.test(i)) {
                grid[r][c] = i;
                break;
            }
        }
    }
    PRINTGrid(grid);
    // cout << endl;
}

int main() {
    FAST_IO
    int testcases = 1;
    // cin >> testcases;
    while (testcases--) {
        solve();
    }
    return 0;
}