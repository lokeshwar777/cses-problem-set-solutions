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
    vector<int> vec(n);
    for (auto &x : vec) cin >> x;
    map<int, int> mp;
    int cnt = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        mp[vec[r]]++;
        while ((int) mp.size() > k) {
            if (--mp[vec[l]] == 0) mp.erase(vec[l]);
            ++l;
        }
        cnt += r - l + 1;
    }
    cout << cnt;
}

int32_t main() {
    FAST_IO
    solve();
}