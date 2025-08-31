/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        set<int> cur_st = {x};
        for (int y : st) cur_st.insert(x + y);
        st.insert(cur_st.begin(), cur_st.end());
    }
    cout << st.size() << '\n';
    for (int x : st) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}