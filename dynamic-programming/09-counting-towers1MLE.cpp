/* 777 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7, MAX_N = 1e4;
int N;
static long long dp[MAX_N + 1][2];

// i -> level/index, j -> 0-horizontal blocks, 1-vertical blocks are before
int rec(int i, int j) {
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    int hb = rec(i - 1, 0);  // horizontal blocks
    int vb = rec(i - 1, 1);  // vertical blocks
    if (j) {
        ans = (4 * vb) % MOD + hb;
    } else {
        ans = (2 * hb) % MOD + vb;
    }
    ans %= MOD;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[1][0] = dp[1][1] = 1;  // base case
    rec(MAX_N, 0);
    int T = 1;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (0 + dp[N][1] + dp[N][0]) % MOD << '\n';
    }
}

// TRY 2
/*
think j as horizontal & vertical blocks are before

case 0: horizontal blocks are before (1x2)
    - extend 1x2 block -> (i - 1, horizontal block)
    - one new 1x2 block -> (i - 1, horizontal block)
    - two new 1x1 blocks -> (i - 1, vertical block)

case 1: vertical blocks are before (two 1x1 blocks at the horizontal block)
    - extend one 1x1 block to the left -> (i - 1, vertical block)
    - extend one 1x1 block to the right -> (i - 1, vertical block)
    - extend both 1x1 blocks -> (i - 1, vertical block)
    - two new 1x1 blocks -> (i - 1, vertical block)
    - one new 1x2 block -> (i - 1, horizontal block)
*/

// TRY 1 (NOT CORRECT)
/*
case 1: if both the blocks are at the same level `i`
  - new blocks
    - one 1x2 block -> (i - 1, same level)
    - one 1x1 block to the left -> (i - 1, different level)
    - one 1x1 block to the right -> (i - 1, different level)
    - two 1x1 blocks -> (i - 1, same level)
  - extend the current block(s) (if they exist)
    - extend (1x2 block / two 1x1 blocks) -> (i - 1, same level)

case 2: if both the blocks are at the different levels `i`
(only place 1 block either to the left or right
i.e bring them to the same level or keep at different levels)
  - new block
    - one 1x1 block to the already extra -> (i - 1, different level)
    - one 1x1 block to the empty slot -> (i - 1, same level)
  - extend the current block(s) (if they exist)
    - extend (one 1x1 block to the already extra) -> (i - 1, different level)
    - extend (one 1x1 block to the empty slot) -> (i - 1, same level)

same level
- -
- -

different levels
- -   or  - -
-           -

// i -> level/index, j -> are both the blocks at the same index/level
int rec(int i, int j) {
    if (i == 0) return j;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    int next_diff = rec(i - 1, 0);
    int next_same = rec(i - 1, 1);
    int cnt = ((j + 1) * ((next_diff + next_same) % MOD)) % MOD;
    if (i < MAX_N) cnt += next_same + (1 - j) * next_diff;
    return ans = cnt % MOD;
}
*/