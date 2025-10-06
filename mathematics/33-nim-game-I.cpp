/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, nim_sum = 0, x;
    cin >> N;
    while (N--) cin >> x, nim_sum ^= x;
    cout << (nim_sum ? "first\n" : "second\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}