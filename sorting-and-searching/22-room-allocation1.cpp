/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> starts(n), ends(n), res(n);
    vector<pair<int, pair<int, int>>> intervals;
    set<int> rooms;
    for (int i = 0; i < n; ++i) {
        cin >> starts[i] >> ends[i];
        intervals.emplace_back(make_pair(starts[i], make_pair(0, i)));
        intervals.emplace_back(make_pair(ends[i], make_pair(1, i)));
        rooms.insert(i + 1);
    }
    sort(intervals.begin(), intervals.end());

    for (auto& [_, p] : intervals) {
        auto& [ty, i] = p;
        if (ty)
            rooms.insert(res[i]);
        else {
            res[i] = *rooms.begin();
            rooms.erase(rooms.begin());
        }
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
    for (auto& x : res) cout << x << " ";
}

int32_t main() {
    FAST_IO
    solve();
}