#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, i64> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int p;
    cin >> p;

    i64 res = cnt[p];

    while (cnt.rbegin()->first >= p) {
        res = max(res, cnt[p]);
        map<int, i64> new_cnt;
        for (auto [x, v]: cnt) {
            int y = (x + 2) / 3;
            new_cnt[y] += v * 2;
        }
        cnt = move(new_cnt);
    }
    cout << res;
    return 0;
}
