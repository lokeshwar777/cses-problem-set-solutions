/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
// const int inf=1e7;
vi vec;
// const int N=1e6;
int n;

void pre() {}

void solve() {
    int x;
    cin >> n >> x;
    vpii pvec;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        pvec.eb(temp, i);
    }
    sortf(pvec);
    int l = 0, r = n - 1;
    while (l < r) {
        int cur_sum = pvec[l].first + pvec[r].first;
        if (cur_sum == x) {
            cout << pvec[l].second << " " << pvec[r].second << endl;
            return;
        }
        if (cur_sum < x)
            ++l;
        else
            --r;
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}