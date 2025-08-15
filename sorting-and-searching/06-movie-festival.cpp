/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortfn(x, fn) sort(all(x), fn)
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
        vec.emplace_back(x, y);
    }
    sortfn(vec, [&](pii a, pii b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    int cur = 0;
    for (auto& [st, end] : vec) {
        if (st >= cur) {
            cur = end;
            ++res;
        }
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