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

vi v1, v2, v3;
int res = 0;

void pre() {}

void solve() {
    int ppl, apts, diff;
    cin >> ppl >> apts >> diff;
    v1.resize(ppl);
    for (auto& x : v1) cin >> x;
    v2.resize(apts);
    for (auto& x : v2) cin >> x;
    sortf(v1);
    sortf(v2);
    for (int pp = 0, ap = 0; pp < ppl && ap < apts;) {
        if (v1[pp] - v2[ap] > diff) {
            ++ap;
            continue;
        }
        if (abs(v1[pp] - v2[ap]) <= diff) {
            ++ap;
            ++res;
        }
        ++pp;
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