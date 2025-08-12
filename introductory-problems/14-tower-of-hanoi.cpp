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
vpii vecp;
// const int N=1e6;
int n;

void pre() {}

void tower_of_hanoi(int n, int source, int destination) {
    if (!n) return;
    int helper = 6 - (source + destination);
    tower_of_hanoi(n - 1, source, helper);
    // cout << source << " " << destination << endl;
    vecp.eb(source, destination);
    tower_of_hanoi(n - 1, helper, destination);
}

void print_vecp(vpii vecp) {
    for (auto &[src, dest] : vecp) {
        cout << src << " " << dest << endl;
    }
}

void solve() {
    cin >> n;
    tower_of_hanoi(n, 1, 3);
    cout << vecp.size() << endl;
    print_vecp(vecp);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}

/*
1 -> 1 3

2
1 -> 1 2
2 -> 1 3
1 -> 2 3

3
1 -> 1 3
2 -> 1 2
1 -> 3 2
3 -> 1 3
1 -> 2 1
2 -> 2 3
1 -> 1 3

4
1 -> 1 2
2 -> 1 3
1 -> 2 3
3 -> 1 2
1 -> 3 1
2 -> 3 2
1 -> 1 2
4 -> 1 3
1 -> 2 3
2 -> 2 1
1 -> 3 1
3 -> 2 3
1 -> 1 2
2 -> 1 3
1 -> 2 3
*/