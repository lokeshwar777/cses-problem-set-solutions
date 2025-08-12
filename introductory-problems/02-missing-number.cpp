/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<int> vec(n - 1);
    for (auto &x : vec) cin >> x;
    int missing_num = 0;
    for (int i = 1; i <= n; ++i) missing_num ^= vec[i - 1] ^ i;
    cout << missing_num;
}
