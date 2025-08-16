/* 777 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Range {
    int start;
    int end;
    int index;
};

void solve() {
    int N;
    cin >> N;
    vector<Range> events(N);
    for (int i = 0; i < N; ++i) {
        cin >> events[i].start;
        cin >> events[i].end;
        events[i].index = i;
    }

    // early starts, late ends first (longer durations first as tie-breakers)
    sort(events.begin(), events.end(), [](Range event1, Range event2) {
        return (event1.start == event2.start) ? event1.end > event2.end
                                              : event1.start < event2.start;
    });

    // is range at `index` contained inside any other range
    vector<int> contained(N), contains(N);
    int cur_max = 0;
    for (int i = 0; i < N; ++i) {
        Range range = events[i];
        if (cur_max >= range.end) contained[range.index] = 1;
        cur_max = max(cur_max, range.end);
    }

    // does range at `index` contains any other range inside it
    int cur_min = INF;
    for (int i = N - 1; i >= 0; --i) {
        Range range = events[i];
        if (cur_min <= range.end) contains[range.index] = 1;
        cur_min = min(cur_min, range.end);
    }

    for (int x : contains) cout << x << " ";
    cout << '\n';
    for (int x : contained) cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

/*
- can be solved using brute -> O(n^2)
- for optimisation -> we need the intervals in a specific order
- sorting! but based on what (starts or ends ?)
- for simplicity lets choose start (left->right is traditional)
- now we do not have to care about start anymore - only think about ends

left->right(1->N)
1. is the current interval contained inside any other interval
    - there need to exist an end before the current interval such that
      the end is greater than the current interval end
    - this implies that the current interval is contained inside that end
    - how? track the maximum end of all the intervals before the current
interval

right->left(N->1)
2. does the current interval contain any other interval inside it
    - there need to exist an end after the current interval such that
      the end is less than the current interval end
    - this implies that the current interval contains that end inside it
    - how? track the minimum end of all the intervals after the current interval

edgecases
- for intervals having same starting points we need to decide upon a criteria
  to sort the ends either greater first or smalller first
- with the below example we can decide that greater ends come first

[3,8], [3,10] -> !X! NO as we know that [3,8] is contained inside [3,10] - (1) &
(2) fail [3,10], [3,8] -> !✔️! YES as [3,8] is contained insdide [3,10] - (1) &
(2) pass

conclusions
- all the intervals before the current interval start at or before the current
start
- in case if two intervals start at the same time
    then all the intervals before the current interval end at or after the
current interval ends
*/