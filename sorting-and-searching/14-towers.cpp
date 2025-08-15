/* 777 */
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int n, x;
    cin >> n;
    vector<int> vec;
    while (n--) {
        cin >> x;
        auto it = upper_bound(vec.begin(), vec.end(), x);
        if (it == vec.end())
            vec.push_back(x);
        else
            *it = x;
    }
    cout << vec.size();
}

int32_t main() {
    FAST_IO
    solve();
}