/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n), pse(n, 0);
    for (int& x : vec) cin >> x;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && vec[st.top()] >= vec[i]) st.pop();
        if (!st.empty()) pse[i] = st.top() + 1;
        st.push(i);
    }
    for (int x : pse) cout << x << ' ';
}

int32_t main() {
    FAST_IO
    solve();
}