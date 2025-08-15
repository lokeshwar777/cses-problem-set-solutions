/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> v(n), ind(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[i] = x;
        ind[x] = i;
    }
    // for (auto &y:ind) cout << y << " ";
    int rounds = 1;
    for (int i = 1; i < n; ++i) rounds += ind[i + 1] < ind[i];
    cout << rounds << '\n';
}

signed main() {
    solve();
    return 0;
}