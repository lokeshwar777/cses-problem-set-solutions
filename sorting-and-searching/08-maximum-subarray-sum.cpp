/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
const int inf = 1e9;
vi vec;
// const int N=1e6;
int n;

void pre() {}

// int rec(int i,int prev){
// 	if(i==n)return prev;
// 	return max(rec(i+1,prev+arr[i]),rec(i+1,arr[i]))
// }
// max(0,rec(0,0));

// default ans - 0 if empty subarrays are allowed, -inf for max
int maxKadane(vector<int> &dp, int ans) {
    int n = dp.size();
    // dp[i] -> max subarray sum ending at i
    for (int i = 0; i < n; ++i) {
        if (i) dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve() {
    cin >> n;
    vec.resize(n);
    for (auto &x : vec) cin >> x;
    cout << maxKadane(vec, -inf) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}