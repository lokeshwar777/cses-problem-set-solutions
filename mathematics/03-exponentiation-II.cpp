/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int bin_exp(int base, int exp, int mod) {
    int res = 1;
    for (; exp; base = (base * base) % mod, exp >>= 1) {
        if (exp & 1) res = (res * base) % mod;
    }
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = bin_exp(b, c, MOD - 1);
    int res = bin_exp(a, x, MOD);
    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}