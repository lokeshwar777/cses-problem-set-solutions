/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n, k;
vector<int> vec;

bool check(int mid) {
    int cnt = 0;
    for (auto& x : vec) {
        cnt += mid / x;
        if (cnt >= k) return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    int low = 1, high = 1e18, mid, ans = 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }
    cout << ans;
}

int32_t main() {
    FAST_IO
    solve();
}