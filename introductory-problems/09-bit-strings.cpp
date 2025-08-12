/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll bin_exp_iter(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    cout << bin_exp_iter(2, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}