/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;
int mul(int a, int b) {
    return (a * b) % MOD;
}

int exp(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << exp(a, b) << endl;
    }
}

int32_t main() {
    FAST_IO
    solve();
}