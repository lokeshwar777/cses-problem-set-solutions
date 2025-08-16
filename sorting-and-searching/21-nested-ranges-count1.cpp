/* 777 */
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class FenwickTree {
   private:
    int SZ;
    vector<int> B;

   public:
    FenwickTree(int N) {
        SZ = N + 2;
        B.resize(SZ, 0);
    }

    void update(int i, int x) {
        for (; i < SZ; i += i & -i) B[i] += x;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += B[i];
        return s;
    }
};

struct Range {
    int start;
    int end;
    int index;
};

void count_ranges() {
    // take input
    int N;
    cin >> N;
    vector<Range> events(N);
    set<int> times;
    for (int i = 0; i < N; ++i) {
        cin >> events[i].start >> events[i].end;
        times.insert({events[i].start, events[i].end});
        events[i].index = i;
    }

    // coordinate compression
    vector<int> unique_times(times.begin(), times.end());
    sort(unique_times.begin(), unique_times.end());
    map<int, int> cx;
    for (int i = 0; i < (int) unique_times.size(); ++i) {
        cx[unique_times[i]] = i + 1;
    }

    // update events with compressed times
    for (Range &range : events) {
        range.start = cx[range.start];
        range.end = cx[range.end];
    }

    // sort events based on compressed times
    sort(events.begin(), events.end(), [](Range range1, Range range2) {
        return (range1.end == range2.end) ? (range1.start > range2.start)
                                          : (range1.end < range2.end);
    });

    // total compressed times
    int max_N = unique_times.size() + 1;
    FenwickTree FT1(max_N), FT2(max_N);
    vector<int> contains(N), contained(N);

    // contains - query over range(start -> end) for each event, later mark at
    // every start
    for (int i = 0; i < N; ++i) {
        Range range = events[i];
        int res = FT1.query(range.end) - FT1.query(range.start - 1);
        FT1.update(range.start, 1);
        contains[range.index] = res;
    }

    // contained - query over range(1 -> start) for each event, later mark at
    // every start
    for (int i = N - 1; i >= 0; --i) {
        Range range = events[i];
        int res = FT2.query(range.start);
        FT2.update(range.start, 1);
        contained[range.index] = res;
    }

    for (int x : contains) cout << x << " ";
    cout << '\n';
    for (int x : contained) cout << x << " ";
}

int main() {
    // comment the below 3 lines to get TLE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    count_ranges();
    return 0;
}