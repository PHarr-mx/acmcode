#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;
const i64 INF = LLONG_MAX / 2;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> cnt;
    for (int i = 0, v; i < n; i++) {
        cin >> v;
        cnt[v]++;
    }
    int res = INF;
    int lease = n;
    for (auto [k, v] : cnt) {
        res = min(res, (n - v) * y);
        lease -= v;
        res = min(res, k * x + lease * y);
    }
    cout << res << '\n';
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
