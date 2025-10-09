/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, nim_sum = 0, x;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x, nim_sum ^= x * (i % 2 == 0);
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

/*
do not touch odd levels
always see that even levels are empty
so the answer is simply nim game on even levels which act as nim piles
*/