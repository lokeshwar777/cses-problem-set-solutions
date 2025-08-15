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

vi vec, v1, v2, v3;
int res = 0;

void pre() {}

void solve() {
    int n, m, x;
    cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        cin >> x;
        ms.insert(x);
    }
    while (m--) {
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.begin()) {
            res = -1;
        } else {
            res = *prev(it);
            ms.erase(prev(it));
        }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre();
    solve();
}