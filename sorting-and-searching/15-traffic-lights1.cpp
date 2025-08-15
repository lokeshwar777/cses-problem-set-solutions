/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, q, cur, nxt, prev;
    cin >> n >> q;
    priority_queue<pair<int, int>> max_heap;
    max_heap.push(make_pair(0, n));
    max_heap.push(make_pair(n, 0));
    set<int> st = {0, n};
    while (q--) {
        cin >> cur;
        auto it = st.upper_bound(cur);
        nxt = *it;
        it--;
        prev = *it;
        st.insert(cur);
        max_heap.push(make_pair(cur - prev, prev));
        max_heap.push(make_pair(nxt - cur, cur));
        while (!max_heap.empty()) {
            auto [length, start] = max_heap.top();
            nxt = *st.upper_bound(start);
            if ((start + length) == nxt) break;
            // cout << start << " " << length << " " << nxt << endl;
            max_heap.pop();
        }
        cout << (max_heap.top().first) << ' ';
    }
}

int32_t main() {
    FAST_IO
    solve();
}