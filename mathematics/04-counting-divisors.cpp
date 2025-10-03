/* 777 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
int divs[MAX_N + 5];

void pre() {
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = i; j <= MAX_N; j += i) {
            divs[j]++;
        }
    }
}

void solve() {
    int N;
    cin >> N;
    cout << divs[N] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}