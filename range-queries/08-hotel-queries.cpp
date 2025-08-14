/* 777 */
#include <bits/stdc++.h>
using namespace std;

pair<int, int> dummy_pair = make_pair(-1, -1);

class SegmentTree {
   private:
    vector<int> arr;
    vector<pair<int, int>> tree;

    int merge(int a, int b) {
        int res = max(a, b);
        return res;
    }

   public:
    SegmentTree(vector<int>& nums) {
        this->arr = nums;
        this->tree.resize(4 * nums.size(), dummy_pair);
    }

    void build(int v, int lo, int hi) {
        if (lo == hi) {
            tree[v] = make_pair(arr[lo], lo);
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(2 * v, lo, mid);
        build(2 * v + 1, mid + 1, hi);
        tree[v] =
            make_pair(merge(tree[2 * v].first, tree[2 * v + 1].first), -1);
    }

    int update_and_query(int v, int lo, int hi, int x) {
        // cout << v << " " << lo << " " << hi << " " << x << endl;
        if (lo == hi) {
            auto [value, index] = tree[v];
            if (x <= value) {
                tree[v] = make_pair(value - x, index);
                return index;
            }
            return -1;
        }

        int mid = lo + (hi - lo) / 2;
        int removed_index = -1;
        if (x <= tree[2 * v].first) {
            removed_index = update_and_query(2 * v, lo, mid, x);
        } else if (x <= tree[2 * v + 1].first) {
            removed_index = update_and_query(2 * v + 1, mid + 1, hi, x);
        }

        tree[v] =
            make_pair(merge(tree[2 * v].first, tree[2 * v + 1].first), -1);

        return removed_index;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int& x : arr) cin >> x;

    SegmentTree* ST = new SegmentTree(arr);
    ST->build(1, 0, N - 1);

    vector<int> qs(Q);
    for (int q = 0; q < Q; ++q) {
        int num;
        cin >> num;
        int ans = ST->update_and_query(1, 0, N - 1, num);
        qs[q] = ans + 1;
    }

    for (int x : qs) cout << x << ' ';
}

int32_t main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}