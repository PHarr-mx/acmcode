#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, b;
    cin >> n >> b;
    vector<pii> a(n);
    for (auto &[p, s]: a) cin >> p >> s;

    multiset<int> cnt;
    for (auto [p, s]: a) cnt.insert(p + s);

    auto calc = [&b, &cnt]() {
        int res = 0, remain = b;
        for (auto it: cnt) {
            if (it > remain) break;
            res++;
            remain -= it;
        }
        return res;
    };
    int res = calc();
    for (auto [p, s]: a) {
        int x = p + s, y = p / 2 + s;
        cnt.erase(cnt.find(x));
        cnt.insert(y);
        res = max(res, calc());
        cnt.erase(cnt.find(y));
        cnt.insert(x);
    }
    cout << res;
    return 0;
}
