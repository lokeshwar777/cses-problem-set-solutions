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
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    vector<ll> vec;
    for (int i = 1; i <= n / 2; ++i) {
        vec.push_back((n >> 1) + i);
        vec.push_back(i);
    }
    if (n & 1) vec.push_back(n);
    for (auto &x : vec) cout << x << " ";
}
