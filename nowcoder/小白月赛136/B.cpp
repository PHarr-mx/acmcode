#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;


void solve() {
    int n, m, x, y, k, res = inf;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0, sum, p, q; i <= k; i ++) {
        p = min(n / 3, i);
        q = min(m / 4 , k - i);
        sum = (n - p) * x + (m - q) * y;
        res = min(res, sum);
    }
    cout << res << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --) solve();
    return 0;
}