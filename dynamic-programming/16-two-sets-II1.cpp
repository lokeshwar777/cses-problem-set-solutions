/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;
int add(int a, int b) {
    return (a + b) % MOD;
}
int modinv(int b) {
    int res = 1;
    int e = MOD - 2;
    while (e) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}
int divmod(int a, int b) {
    return a * modinv(b) % MOD;
}

vector<vector<int>> dp;
int n, offset, limit;

void solve() {
    cin >> n;
    offset = n * (n + 1) / 2;  // maximum possible sum
    limit = 2 * offset;
    dp.resize(2, vector<int>(limit + 1));
    dp[(n + 1) & 1][offset] = 1;
    for (int num = n; num > 0; num--) {
        fill(dp[num & 1].begin(), dp[num & 1].end(), 0);
        for (int sum = 0; sum <= limit; ++sum) {
            if (sum >= num)
                dp[num & 1][sum] =
                    add(dp[num & 1][sum], dp[(num + 1) & 1][sum - num]);
            if (sum + num <= limit)
                dp[num & 1][sum] =
                    add(dp[num & 1][sum], dp[(num + 1) & 1][sum + num]);
        }
    }
    cout << divmod(dp[1][offset], 2);
}

int32_t main() {
    FAST_IO
    solve();
}