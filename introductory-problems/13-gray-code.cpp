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
// const int inf=1e9;
vi vec;
// const int N=1e6;
int n;

void pre() {}

string bin(int bits, int n) {
    string s = "";
    for (int i = bits - 1; i >= 0; --i) {
        char c = '0' + ((n >> i) & 1);
        s.pb(c);
    }
    return s;
}

void solve() {
    cin >> n;
    vector<int> vec = {0};
    for (int x = 1; x < (1 << n); x <<= 1) {
        for (int i = x - 1; i >= 0; --i) {
            vec.push_back(x + vec[i]);
        }
    }
    for (auto &x : vec) cout << bin(n, x) << endl;
    // for(int i=0;i<(1<<n);++i)cout<<bin(n,i)<<" "<<i<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}