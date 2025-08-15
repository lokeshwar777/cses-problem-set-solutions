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

int check(int max_sum) {
    int cur_sum = 0, cnt = 1;
    for (int x : vec) {
        if (cur_sum + x > max_sum) {
            cur_sum = x;
            cnt++;
        } else
            cur_sum += x;
        if (cnt > k) return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> k;
    vec.resize(n);
    for (int &x : vec) cin >> x;
    int lo = *max_element(vec.begin(), vec.end()),
        hi = accumulate(vec.begin(), vec.end(), 0LL), ans = hi;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    cout << ans;
}

int32_t main() {
    FAST_IO
    solve();
}