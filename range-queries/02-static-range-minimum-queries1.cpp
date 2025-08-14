/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using mii = map<int, int>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
// const int INF=1e9;
const int INF = LLONG_MAX;
vi vec;
// vpii vecp;
// const int N=1e6;
int n;
int res = 0;

void pre() {}

class SegmentTree {
    vector<int> tree;

   public:
    SegmentTree(vi& arr) {
        int N = arr.size();
        tree.resize(4 * N);
        build(arr, 0, 0, N - 1);
    }

    int merge(int a, int b) { return min(a, b); }

    int build(vector<int>& arr, int node, int low, int high) {
        int mid = ((high - low) >> 1) + low;
        if (low == high) {
            tree[node] = arr[mid];
        } else {
            int leftSubtree = build(arr, (node << 1) + 1, low, mid);
            int rightSubtree = build(arr, (node << 1) + 2, mid + 1, high);
            tree[node] = merge(leftSubtree, rightSubtree);
        }
        return tree[node];
    }

    int query(int node, int low, int high, int left, int right) {
        // no overlap (fully outiside query)
        if (high < left || right < low) {
            return INF;
        }

        // complete overlap (fully inside query)
        if (left <= low && high <= right) {
            return tree[node];
        }

        // partially overlap
        int mid = ((high - low) >> 1) + low;
        int leftSubtree = query((node << 1) + 1, low, mid, left, right);
        int rightSubtree = query((node << 1) + 2, mid + 1, high, left, right);
        return merge(leftSubtree, rightSubtree);
    }

    void printRanges(int node, int low, int high) {
        cout << "node " << node << " => range [" << low << ", " << high
             << "], value = " << tree[node] << endl;

        if (low == high) {
            return;
        }
        int mid = ((high - low) >> 1) + low;
        printRanges((node << 1) + 1, low, mid);
        printRanges((node << 1) + 2, mid + 1, high);
    }
};

void solve() {
    int queries;
    cin >> n >> queries;
    vec.resize(n);
    for (auto& x : vec) cin >> x;
    SegmentTree segTree(vec);
    // segTree.printRanges(0, 0, n-1);

    while (queries--) {
        int left, right;
        cin >> left >> right;
        res = segTree.query(0, 0, n - 1, left - 1, right - 1);
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}