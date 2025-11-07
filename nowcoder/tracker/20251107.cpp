#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    double mm;
    cin >> n >> mm;
    int m = round((mm - 1.0) * 100);
    int x = 0, y = 0, res = 0;
    while (n > 0) {
        x = n * 100;
        y = min(10000, n * m);
        n = x / 200;
        res += x / 10;
        res += y / 10;
    }
    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
