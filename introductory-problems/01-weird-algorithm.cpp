/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n & 1)
            n = (n * 3) + 1;
        else
            n >>= 1;
    }
    cout << 1;
}
