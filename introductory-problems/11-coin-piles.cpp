/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;
vector<int> vec;

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if ((a > (b << 1)) || (b > (a << 1))) {
            cout << "NO\n";
            continue;
        }
        cout << (((a + b) % 3) ? "NO" : "YES") << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}