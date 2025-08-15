/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int n, x;
    cin >> n;
    set<int> s;
    while (n--) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}