/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int res = 0;

void pre() {}

void solve() {
    int n, x, y;
    cin >> n;
    vpii vec;
    while (n--) {
        cin >> x >> y;
        vec.emplace_back(x, 1);
        vec.emplace_back(y, -1);
    }
    sortf(vec);
    int cur = 0;
    for (auto& [_, ty] : vec) {
        cur += ty;
        res = max(res, cur);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre();
    solve();
}