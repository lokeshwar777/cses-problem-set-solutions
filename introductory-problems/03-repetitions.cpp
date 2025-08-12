/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

// const int MOD=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ll n;cin>>n;
    // vector<int>vec(n-1);
    // for(auto &x:vec)cin>>x;
    string s;
    cin >> s;
    int streak = 1, max_streak = 1;
    for (int i = 1; i < (int) s.size(); ++i) {
        if (s[i] == s[i - 1])
            streak++;
        else
            streak = 1;
        max_streak = max(max_streak, streak);
    }
    cout << max_streak;
}
