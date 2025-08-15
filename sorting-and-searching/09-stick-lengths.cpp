/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using mii = map<int, int>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
// const int INF=1e9;
// const int INF = LLONG_MAX;
vi vec;
// vpii vecp;
// const int N=1e6;
int n;
int res = 0;

void pre() {}

void solve() {
    cin >> n;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    sort(vec.begin(), vec.end());
    int target = vec[n / 2];
    int sum = 0;
    for (auto& x : vec) sum += abs(x - target);
    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}