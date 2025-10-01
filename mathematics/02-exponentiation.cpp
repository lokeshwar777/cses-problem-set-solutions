/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int bin_exp(int base, int exp, int mod) {
    int res = 1;
    for (; exp; base = (base * base) % mod, exp >>= 1) {
        if (exp & 1) res = (res * base) % mod;
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << bin_exp(a, b, 1e9 + 7) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}