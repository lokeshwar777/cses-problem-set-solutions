/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;

long long mul(long long a, long long b) {
    return (1LL * a * b) % MOD;
}

void solve() {
    map<int, int> freq;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        freq[x]++;
    }
    long long cnt = 1LL;
    for (auto& [_, f] : freq) cnt = mul(cnt, f + 1);
    cout << cnt - 1;
}

int32_t main() {
    FAST_IO
    solve();
}