/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;
    set<int> st;
    for (int l = 0, r = 0; r < n; ++r) {
        while (st.count(vec[r])) st.erase(vec[l++]);
        st.insert(vec[r]);
        cnt += r - l + 1;
    }
    cout << cnt;
}

int32_t main() {
    FAST_IO
    solve();
}