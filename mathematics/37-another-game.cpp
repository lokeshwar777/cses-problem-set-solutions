/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, x, has_odd = 0;
    cin >> N;
    while (N--) cin >> x, has_odd |= x & 1;
    cout << (has_odd ? "first\n" : "second\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}

/*
- min(all heaps) = 1 -> W
- you don't want to touch even numbered heaps that make you lose
- so you always try to make all the heaps even and you can only make this happen
if you have atleast 1 odd numbered heap

observation: even if there is a single heap with odd number of coins you win
*/