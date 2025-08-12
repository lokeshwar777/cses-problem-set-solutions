/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long

// const int MOD=1e9+7;

void solve() {
    string s;
    cin >> s;
    int freq[26] = {0};
    for (auto &c : s) freq[c - 'A']++;
    string res;
    int oddcnt = 0, oddind = -1;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] & 1) {
            oddcnt++;
            oddind = i;
        }
        for (int f = 0; f < freq[i] / 2; ++f) res.push_back('A' + i);
    }
    if (oddcnt > 1) {
        cout << "NO SOLUTION";
        return;
    }
    cout << ((oddind != -1)
                 ? (res + char('A' + oddind) + string(res.rbegin(), res.rend()))
                 : res + string(res.rbegin(), res.rend()));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}