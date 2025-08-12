/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

// const int MOD=1e9+7;

void solve() {
    ll n;
    cin >> n;
    ll pairs = (n + 1) >> 1;  // floor of half of n
    if ((pairs & 1)) {        // can't divide equally
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << pairs << '\n';
    for (int i = 0; i < pairs / 2; ++i)
        cout << i + 1 << " " << n - i - (n & 1) << " ";  // print half pairs

    cout << '\n' << n - pairs << '\n';
    for (int i = pairs / 2; i < pairs - (n & 1); ++i)
        cout << i + 1 << " " << n - i - (n & 1) << " ";
    if (n & 1) cout << n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

n-even,pairs-even (YES)
1 2 3 4 5 6 7 8
10 11 12 13 14 15 16

n-even,pairs-odd
1 2 3 4 5 6 7 8 9
10 11 12 13 14 15 16 17 18

n-odd,pairs-odd+1=even (YES)
1 2 3 4 5 6 7 8 9
10 11 12 13 14 15 16 17 18
19

n-odd,pairs-even+1=odd
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17

n|pairs  even 	odd
even 	 YES	NO
odd		 YES 	NO
*/