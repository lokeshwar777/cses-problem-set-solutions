/* 777 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
int vis[MAX_N + 5];

void solve() {
    int N, x;
    cin >> N;
    int res = 1;
    while (N--) {
        cin >> x;
        for (int i = 1; i * i <= x; i++) {
            if (x % i) continue;
            int ii = x / i;
            vis[i]++;
            if (ii != i) vis[ii]++;
        }
    }
    for (int i = 1; i <= MAX_N; ++i) {
        if (vis[i] > 1) res = i;
    }
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}