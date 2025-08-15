/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, m, cnt = 1;
    cin >> n >> m;
    vector<int> vec(n + 1), pos(n + 2, 0);
    pos[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
        pos[vec[i]] = i;
    }
    for (int x = 2; x <= n; ++x) cnt += pos[x - 1] > pos[x];
    while (m--) {
        int i, j;
        cin >> i >> j;
        set<int> st = {vec[i], vec[i] + 1, vec[j], vec[j] + 1};

        for (auto& x : st) cnt -= pos[x - 1] > pos[x];

        swap(vec[i], vec[j]);
        swap(pos[vec[i]], pos[vec[j]]);

        for (auto& x : st) cnt += pos[x - 1] > pos[x];

        cout << cnt << '\n';
    }
}

int32_t main() {
    FAST_IO
    solve();
}