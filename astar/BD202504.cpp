#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == 1) {
        cout << "0\n";
        return;
    }
    if (l == r) {
        cout << "infty\n";
        return;
    }

    int a0 = l - 1, d = r - l;

    int res = (a0 + a0 % d) * (a0 / d + 1) / 2;
    cout << res << "\n";
}


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
