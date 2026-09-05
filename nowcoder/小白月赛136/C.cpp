#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;
using i64 = long long;


void solve() {
    i64 n, ax, ay, bx, by;
    string s;
    cin >> n >> ax >> ay >> bx >> by >> s;
    cout << n + abs(ax - bx) + abs(ay - by) << "\n";
    for (auto c : s) {
        if (c == 'L') {
            cout << "AB"[ax > bx];
        } else if (c == 'R') {
            cout << "BA"[ax > bx];
        } else if (c == 'D') {
            cout << "AB"[ay > by];
        } else {
            cout << "BA"[ay > by];
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
