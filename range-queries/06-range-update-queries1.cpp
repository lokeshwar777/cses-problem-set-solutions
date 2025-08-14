/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
int add(int a, int b) {
    return (a + b) % MOD;
}

class SegmentTree {
   private:
    vector<int> arr;
    vector<int> tree;

    int merge(int a, int b) {
        int res = a + b;
        return res;
    }

   public:
    SegmentTree(vector<int>& nums) {
        this->arr = nums;
        this->tree.resize(4 * nums.size(), 0);
    }

    void build(int v, int lo, int hi) {
        if (lo == hi) {
            tree[v] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(2 * v, lo, mid);
        build(2 * v + 1, mid + 1, hi);
    }

    void update(int v, int lo, int hi, int l, int r, int x) {
        if (l > r) return;
        if (lo == l && r == hi) {
            tree[v] += x;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        update(2 * v, lo, mid, l, min(mid, r), x);
        update(2 * v + 1, mid + 1, hi, max(mid + 1, l), r, x);
    }

    int query(int v, int lo, int hi, int k) {
        if (lo > hi) return 0;
        if (lo == hi) return tree[v];
        int mid = lo + (hi - lo) / 2;
        int cnt = tree[v];
        if (k <= mid) {
            cnt += query(2 * v, lo, mid, k);
        } else {
            cnt += query(2 * v + 1, mid + 1, hi, k);
        }
        return cnt;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int& x : arr) cin >> x;

    SegmentTree* ST = new SegmentTree(arr);
    ST->build(1, 0, N - 1);

    vector<int> qs;
    for (int q = 0; q < Q; ++q) {
        int ty, a, b, c;
        cin >> ty;
        if (ty == 1) {
            cin >> a >> b >> c;
            ST->update(1, 0, N - 1, a - 1, b - 1, c);  // 1-based
        } else {
            cin >> a;
            int res = ST->query(1, 0, N - 1, a - 1);  // 1-based
            qs.push_back(res);
        }
    }

    for (int x : qs) cout << x << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}