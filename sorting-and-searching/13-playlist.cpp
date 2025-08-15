/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortfn(x, fn) sort(all(x), fn)
#define sortr(x) sort(all(x), greater<int>())

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int res = 0;

void pre() {}

void solve() {
    int n;
    cin >> n;
    vi vec(n);
    map<int, int> freq;
    for (int right = 0, left = 0; right < n; ++right) {
        cin >> vec[right];
        freq[vec[right]]++;
        while (freq[vec[right]] > 1) freq[vec[left++]]--;
        res = max(res, right - left + 1);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre();
    solve();
}