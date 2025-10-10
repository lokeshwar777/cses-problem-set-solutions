/* 777 */
#include <bits/stdc++.h>
using namespace std;

int mex(set<int> &st) {
    int ans = 0;
    while (st.count(ans)) ans++;
    return ans;
}

const int MAX_N = 1500;
int dp[MAX_N + 5];

void pre() {
    for (int i = 1; i <= MAX_N; ++i) {
        set<int> st;
        for (int j = 1; j < i; ++j) {
            if (j == i - j) continue;
            st.insert(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(st);
    }
}

void solve() {
    int N;
    cin >> N;
    cout << ((N > MAX_N || dp[N]) ? "first" : "second") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre();
    // for (int i = 1; i <= MAX_N; ++i) cout << i << " " << (dp[i] ? 'F' : 'S')
    // << '\n';

    int T = 1;
    cin >> T;
    while (T--) solve();
}

// FAIL 1
/*
int dp[205];
void pre() {
    int n = 200;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (j == i - j) continue;
            dp[i] |= !dp[j] & !dp[i - j];
        }
    }
}

string exceptions[4] = {"", "second", "second", "first"};
string pattern[3] = {"first", "second", "first"};
void solve() {
    int N;
    cin >> N;
    cout << (N < 4 ? exceptions[N] : pattern[N % 3]) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    pre();
    for (int i = 1; i < 200; ++i) cout << i << " " << (dp[i] ? 'F' : 'S') <<
'\n';
}

// commented code helped to recognise the pattern/period
// 1 -> S
// 2 -> S
// 3 ... INF ->
//     N % 3 is 1 -> S
//     rest -> F
*/