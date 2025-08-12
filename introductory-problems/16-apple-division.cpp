/* 777 */
#include "bits/stdc++.h"
#define int long long
using namespace std;

int n;

int solve(vector<int> &vec, int i, int x) {
    if (i == n) return abs(x);
    return min(solve(vec, i + 1, x + vec[i]), solve(vec, i + 1, x - vec[i]));
}

signed main() {
    cin >> n;
    vector<int> vec(n), ans;
    for (int i = 0; i < n; ++i) cin >> vec[i];
    int res = solve(vec, 0, 0);
    cout << res << endl;
    return 0;
}