/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, nim_sum = 0, x;
    cin >> N;
    while (N--) cin >> x, nim_sum ^= x % 4;
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
using sprauge-grundy theorem
 - nim sum of grundy numbers for composite games -> nim pile
 - G1(x1) ^ G2(x2) ^ G3(x3) .. ^ G(x4) -> final nim-sum
 - grundy recurrence for this problem is X mod 4 for each of the piles
 - rest is same as simple nim game
*/