/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

// const int MOD=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (auto &x : vec) cin >> x;
    ll moves = 0, maxi = vec[0];
    for (int i = 1; i < n; ++i) {
        moves += max(0LL, maxi - vec[i]);
        maxi = max(maxi, vec[i]);
    }
    cout << moves;
}