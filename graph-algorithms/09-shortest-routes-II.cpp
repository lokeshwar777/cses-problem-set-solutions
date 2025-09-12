/* 777 */
#include "bits/stdc++.h"
using namespace std;
#define int long long

const int MAX_N = 2e6 + 5, MAX_NN = 505, INF = 4e18;
int N, M, Q, dp[MAX_NN][MAX_NN];

// Floyd–Warshall algorithm -> O(V^3) - APSP
void floyd_warshall() {
    for (int k = 1; k <= N; ++k) {          // intermediate
        for (int i = 1; i <= N; ++i) {      // src
            for (int j = 1; j <= N; ++j) {  // dest
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

void solve() {
    cin >> N >> M >> Q;

    // init
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) dp[i][j] = i == j ? 0 : INF;
    }

    // input + build
    for (int u, v, i = 0; i < M; ++i) {
        int w;
        cin >> u >> v >> w;

        // handle multiple edges between same pair of nodes
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    // compute APSP
    floyd_warshall();

    // handle queries
    for (int q = 0; q < Q; ++q) {
        int i, j;
        cin >> i >> j;
        if (dp[i][j] == INF) dp[i][j] = -1;
        cout << dp[i][j] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}