/* 777 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
int dp[MAX_N][2];
vector<int> g[MAX_N];

// dp(u, x) -> maximum matchings you can get at node `u`

int dfs(int u, int par, int x) {
    if (dp[u][x] != -1) return dp[u][x];
    int ans = 0, xt = 0;  // xt - extra
    for (int v : g[u]) {
        if (v == par) continue;
        int pick = dfs(v, u, 0);
        int notpick = dfs(v, u, 1);
        ans += max(pick, notpick);
        xt = max(xt, 1 + pick - max(pick, notpick));
    }
    return dp[u][x] = ans + (x * xt);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << max(dfs(1, 0, 1), dfs(1, 0, 0));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

/*
- dp(u, x) -> denotes a state where we can get maximum matchings at node `u`
given that
    if `x` is 1 -> you can make a pair (u, v) with any of the neighbor `v`
    if `x` is 0 -> you can't make a pair involving node `u` anymore

- for each node `u` you can either choose dp(v, 0) or dp(v, 1) so we choose the
max of both

dp(u, 0) -> sum(max(dp(v, 1), dp(v, 0)))

dp(u, 1) -> sum(max(dp(v, 1), dp(v, 0))) for all neighbors except the chosen one
`v` we consider on dp(v, 0) for that

            S - max(pick, not pick) + pick <-----maximise
            so we need the maximum (pick - max(pick, not pick)) which is extra
*/