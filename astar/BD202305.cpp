#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int inf = INT_MAX / 2;

void solve() {
    int p, k;
    cin >> p >> k;
    int l = 0, r = k, res = -1;

    auto calc = [&p](int x) {
        if (p == 1 and x != 0) return inf;
        int ans = x;
        while (x >= p) {
            ans += x / p;
            x = (x % p) + (x / p);
        }
        return ans;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (calc(mid) >= k) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
