#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> ans(q + 1);
    i64 base = 0;
    int N = n * m;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '1') base |= (1LL << i);
    }
    vector<i64> v(q);
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            if (c == '1') v[j] |= (1LL << i);
        }
    }
    i64 target = (1LL << N) - 1;
    for (int x = 0, X = 1 << q; x < X; x++) {
        bool flag = true;
        i64 cnt = base;

        for (int i = 0; i < q and flag; i++) {
            if ((x & (1 << i)) == 0) continue;
            if (base & v[i]) flag = false;
            cnt |= v[i];
        }

        if (not flag) continue;
        if (cnt != target) continue;
        vector<int> res;
        for (int i = 0; i < q; i++) {
            if (x & (1 << i)) res.push_back(i);
        }
        if (res.size() < ans.size()) ans = move(res);
    }
    if (ans.size() > q) {
        cout << -1;
    } else {
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i + 1 << ' ';
    }
    return 0;
}
