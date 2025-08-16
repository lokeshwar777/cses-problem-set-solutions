/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> vec(N);
    for (int &x : vec) cin >> x;
    set<pair<int, int>> pairs;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            pairs.insert({i, j});
        }
    }
    map<int, vector<pair<int, int>>> mp;
    for (auto [i, j] : pairs) {
        int cur_sum = vec[i] + vec[j];
        int complement_sum = X - cur_sum;
        if (mp.count(complement_sum)) {
            for (auto [x, y] : mp[complement_sum]) {
                set<int> st({i, j, x, y});
                if ((int) st.size() == 4) {
                    cout << (i + 1) << ' ' << (j + 1) << ' ' << (x + 1) << ' '
                         << (y + 1);
                    return;
                }
            }
        }
        mp[cur_sum].push_back({i, j});
    }
    cout << "IMPOSSIBLE";
}

// FAILING 1: extension for 3 sum
/*
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> vec;
    for (int i = 1 ; i <= n ; ++i) {
        int x; cin >> x;
        vec.emplace_back(x, i);
    }
    sort(vec.begin(), vec.end());
    map<int,int> mp = {vec[0]};
    for (int i = 1 ; i < n - 2 ; ++i) {
        int cur = vec[i].first;
        for (int l = i + 1, r = n - 1 ; l < r ; ) {
            cur += vec[l].first + vec[r].first;
            int req = k - cur;
            if (mp.count(req)) {
                cout << vec[i].second << " " << vec[l].second << " " <<
vec[r].second << " " << mp[req]; return;
            }
            if (cur < req) ++l;
            else --r;
        }
        mp.insert(vec[i]);
    }
    // for (auto [x,y]:mp) cout << x << " " << y << endl;
    cout << "IMPOSSIBLE";
}
*/

int32_t main() {
    FAST_IO
    solve();
}

// ALGO
/*
- brute force solution -> O(n^4)
- slightly better solution with sorting + 2 pointer -> O(n^3)
- how can we make it better?

observations:
- n <= 1000 -> this mean there can be atmost 1000C2 pairs i.e 1000*999/2 pairs =
499500 ~ 5e5

1. generate all pairs (i, j) , i=1->N, such that i < j
2. store the pairs in a set or (vector + sort)
3. take a map to store all the complementary sums like map[complementary
sum]->vector of pairs
4. iterater over the sorted pairs, for each pair
    check if the complement sum exists
    then if any of the pair forming the complementary sum & the current pair are
all distinct

    if no pair is found -> IMPOSSIBLE
*/