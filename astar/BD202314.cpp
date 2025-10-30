#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &[p, v]: a) cin >> p >> v;
    sort(a.begin(), a.end(), [&](const pii &x, const pii &y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });
    reverse(a.begin(), a.end());
    int res = 1, cnt = 0, lst_p = inf, min_v = inf;
    for (auto [p, v]: a) {
        if (p == lst_p) {
            cnt++;
            min_v = min(min_v, v);
        } else if (v > min_v) {
            cnt++;
        } else {
            min_v = v;
            cnt = 1;
        }
        res = max(res, cnt);
        lst_p = p;
    }
    cout << res;
    return 0;
}
