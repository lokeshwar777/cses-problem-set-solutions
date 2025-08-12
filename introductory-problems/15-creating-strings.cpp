/* 777 */
#include "bits/stdc++.h"
#define int long long
using namespace std;

int n;

vector<string> solve(string &s) {
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return ans;
}

signed main() {
    string s;
    cin >> s;
    n = s.size();
    vector<string> res = solve(s);
    cout << res.size() << endl;
    for (const string &x : res) cout << x << endl;
    return 0;
}