/* 777 */

#include "bits/stdc++.h"
#define int long long
using namespace std;

int n;

void solve(int x, string &s, string temp, vector<int> taken, set<string> &res) {
    if (x == n) {
        res.insert(temp);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            temp.push_back(s[i]);
            taken[i] = 1;
            solve(x + 1, s, temp, taken, res);
            taken[i] = 0;     // backtrack
            temp.pop_back();  // backtrack
        }
    }
}

signed main() {
    string s;
    cin >> s;
    n = s.size();
    set<string> res;
    vector<int> taken(n, 0);
    string temp;
    solve(0, s, temp, taken, res);
    cout << res.size() << endl;
    for (const string &x : res) cout << x << endl;
    return 0;
