/* 777 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, k;
    cin >> N >> k;
    vector<pair<int, int>> events(N);
    for (auto &[end, start] : events) cin >> start >> end;
    sort(events.begin(), events.end());
    multiset<int> endTimes;
    int cnt = 0;
    for (auto &[end, start] : events) {
        auto it = endTimes.upper_bound(start);
        if (it == endTimes.begin() && (int) endTimes.size() == k) {
            continue;
        }
        cnt++;
        if (it != endTimes.begin()) {
            endTimes.erase(--it);
        }
        endTimes.insert(end);
    }
    cout << cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
