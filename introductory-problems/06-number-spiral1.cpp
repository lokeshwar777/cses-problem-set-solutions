/* 777 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n--) {
        long long row, col;
        cin >> row >> col;
        row--;
        col--;
        if (row == col) {
            cout << (row * row) + row + 1 << '\n';
        } else if (row < col) {
            if (col & 1) {
                cout << (col * col) + row + 1 << '\n';
            } else {
                cout << ((col + 1) * (col + 1)) - row << '\n';
            }
        } else {
            if (row & 1) {
                cout << ((row + 1) * (row + 1)) - col << '\n';
            } else {
                cout << (row * row) + col + 1 << '\n';
            }
        }
    }
}