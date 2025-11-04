#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = 0, res = 0;

    while (r < n) {
        while(a[r] - a[l] > k) l ++;
        res = max(res, r - l + 1);
        r ++;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}
