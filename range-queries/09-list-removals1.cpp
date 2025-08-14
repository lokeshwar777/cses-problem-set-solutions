/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

// (count, value)
pair<int, int> dummy_pair = make_pair(0, 0);

class SegmentTree {
   private:
    vector<int> arr;
    vector<pair<int, int>> tree;

    int merge(int a, int b) {
        int res = a + b;
        return res;
    }

   public:
    SegmentTree(vector<int>& nums) {
        this->arr = nums;
        this->tree.resize(4 * nums.size(), dummy_pair);
    }

    void build(int v, int lo, int hi) {
        if (lo == hi) {
            tree[v] = make_pair(1, arr[lo]);
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(2 * v, lo, mid);
        build(2 * v + 1, mid + 1, hi);
        tree[v] = make_pair(merge(tree[2 * v].first, tree[2 * v + 1].first), 0);
    }

    int update_and_query(int v, int lo, int hi, int k) {
        if (lo == hi) {
            if (k != 1) return 0;
            tree[v].first = 0;
            return tree[v].second;
        }

        int mid = lo + (hi - lo) / 2;
        int removed_value = 0, left = tree[2 * v].first;
        if (k <= left) {
            removed_value = update_and_query(2 * v, lo, mid, k);
        } else {
            removed_value = update_and_query(2 * v + 1, mid + 1, hi, k - left);
        }

        tree[v] = make_pair(merge(tree[2 * v].first, tree[2 * v + 1].first), 0);

        return removed_value;
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& x : arr) cin >> x;

    SegmentTree* ST = new SegmentTree(arr);
    ST->build(1, 0, N - 1);

    vector<int> qs(N);
    for (int q = 0; q < N; ++q) {
        int num;
        cin >> num;
        int ans = ST->update_and_query(1, 0, N - 1, num);
        qs[q] = ans;
    }

    for (int x : qs) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}