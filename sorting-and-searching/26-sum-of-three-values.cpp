/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        vec.emplace_back(x, i);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 2; ++i) {
        int req = k - vec[i].first;
        if (req <= 0) continue;
        for (int l = i + 1, r = n - 1; l < r;) {
            int cur = vec[l].first + vec[r].first;
            if (cur == req) {
                cout << vec[i].second << " " << vec[l].second << " "
                     << vec[r].second;
                return;
            }
            if (cur < req)
                ++l;
            else
                --r;
        }
    }
    cout << "IMPOSSIBLE";
}

int32_t main() {
    FAST_IO
    solve();
}