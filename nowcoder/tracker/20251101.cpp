#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    map<int, vector<int> > fact_count;
    auto calc = [](int x) {
        int ans = 0;
        for (int i = 1, j; i * i <= x; i++) {
            if (x % i != 0) continue;
            j = x / i;
            ans += 1 + (i != j);
        }
        return ans;
    };

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        fact_count[calc(x)].push_back(i);
    }

    auto count = [](int L, int R, vector<int> &arr) {
        i64 ans = upper_bound(arr.begin(), arr.end(), R) - lower_bound(arr.begin(), arr.end(), L);
        return ans * (ans - 1) / 2;
    };
    for (int l, r; q; q--) {
        cin >> l >> r;
        i64 res = 0;
        for (auto &[_, arr]: fact_count) {
            res += count(l, r, arr);
        }
        cout << res << '\n';
    }
    return 0;
}
