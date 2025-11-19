#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

struct dsu {
    vector<int> parent;

    dsu(int n) : parent(n + 1, -1) {
    }

    int find(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, c;
    cin >> n >> m >> c;

    using Edge = array<int, 3>;
    vector<Edge> edges(m);
    for (auto &[w, x, y]: edges) cin >> x >> y >> w;
    sort(edges.begin(), edges.end());
    auto check = [&n, &edges, &c](int p) {
        vector<int> val;
        dsu d(n);
        for (const auto &[w, x, y]: edges) {
            if (d.same(x, y)) continue;
            d.merge(x, y);
            if (w <= p) continue;
            val.push_back(w);
        }
        int sum = 0;
        reverse(val.begin(), val.end());
        for (int i = 0; i < val.size(); i ++)
            sum += val[i] * (i + 1);
        return sum <= c;
    };

    int l = 0, r = inf, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << res;
    return 0;
}
