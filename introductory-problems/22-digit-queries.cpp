/* 777 */
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using mii = map<int, int>;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sortf(x) sort(all(x))
#define sortr(x) sort(all(x), greater<int>())

// const int MOD=1e9+7;
// const int inf=1e9;
vi vec;
// vpii vecp;
// const int N=1e6;
int n;
int res = 0;

void pre() {}

int getDigits(int num) {
    return (int) (log10(num)) + 1;
}

void visualise(int limit) {
    // int digits = getDigits(limit);
    // cout << digits << endl;

    for (int i = 1; i <= limit; ++i) {
        cout << i;
    }

    // mii m;
    // for(int i = 1 ; i <= limit ; ++i) {
    // 	m[getDigits(i)]++;
    // }
    // for(auto &[digits,count]:m) cout << digits << " -> " << count << endl;
}

// alternative approach
/*
int rec(int num) {
        int curr_chunk = 9, digits = 1, k = num;
        while (k > curr_chunk) {
                k -= curr_chunk;
                digits++;
                curr_chunk = 9 * pow(10, digits - 1) * digits;
        }

        k--; // 0 - based

        res = pow(10, digits - 1) + (k / digits);
        int position = (k % digits);
        // cout << "input : " << num << ", chunk : " << curr_chunk << ", digits
: " << digits << ", k : " << k << ", position : " << position << endl;

        // res = (int)(res / pow(10, digits - position - 1)) % 10; // extract
the desired digit string res_string = to_string(res); res = res_string[position]
- '0'; return res;
}
*/

int rec(int num) {
    int start = 1, digits = 1, k = num, curr_chunk = 9;
    while (k > curr_chunk) {
        k -= curr_chunk;
        start *= 10;
        digits++;
        curr_chunk = 9 * start * digits;
    }

    // k - 1 -> 0 - based
    res = start + ((k - 1) / digits);
    int position = ((k - 1) % digits);

    string res_string = to_string(res);
    res = res_string[position] - '0';

    return res;
}

// GPT (for reference)
/*
long long rec(long long k) {
    long long digit_length = 1;  // Starting with 1-digit numbers
    long long curr_chunk = 9;    // 1-digit numbers contribute 9 digits
    long long start = 1;         // Starting number in each chunk (1, 10,
    // 100, etc.)

    // Step 1: Find the chunk where k-th digit falls
    while (k > curr_chunk) {
        k -= curr_chunk;          // Reduce k by the total digits in the
        current chunk digit_length++;            // Move to the next chunk
        (2-digit, 3-digit, ...) start *= 10;               // Start of the
        next chunk (10, 100, 1000, etc.) curr_chunk = 9 * start *
        digit_length;  // Number of digits in this chunk
    }

    // Step 2: Find the number containing the k-th digit
    long long number = start + (k - 1) / digit_length;  // Find the exact
    number int position_in_number = (k - 1) % digit_length;    // Find the
    digit position in that number

    // Step 3: Extract the digit
    string num_str = to_string(number);  // Convert number to string
    return num_str[position_in_number] - '0';  // Convert the character to
    the digit
}
*/

void solve() {
    cin >> n;
    while (n--) {
        int q;
        cin >> q;
        cout << rec(q) << endl;
    }
    // visualise(100);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    solve();
}

/*
1 -> 1-9 = 9 (123..9 - 9*1)
2 -> 10-99 = 90 (101112..99 - 90*2)
3 -> 100-999 = 900 (100101102..999 - 900*3)
.
n -> 9 * (10 ** (n-1))

chunk -> 9 * (10 ** (n-1)) * (n)
*/