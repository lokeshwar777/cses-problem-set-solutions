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
    set<int> st;
    while (n) st.insert(n--);
    auto it = st.begin();
    while (!st.empty()) {
        if ((++it) == st.end()) it = st.begin();
        cout << *it << " ";
        st.erase(it++);
        if (it == st.end()) it = st.begin();
    }
}

int32_t main() {
    FAST_IO
    solve();
}