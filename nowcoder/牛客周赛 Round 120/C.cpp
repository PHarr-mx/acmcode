#include <math.h>
#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

void test(int n, int m) {
    using pii = pair<int,int>;
    vector<pii> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    queue<pii> que;
    // int n = 3, m = 4;
    vector vis(n, vector<int>(m));
    vis[0][0] = 1;
    que.push({0, 0});
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (auto [dx, dy] : d) {
            int fx = x + dx, fy = y + dy;
            if (fx < 0 or fy < 0 or fx >= n or fy >= m) continue;
            if (vis[fx][fy]) continue;
            vis[fx][fy] = 1;
            que.push({fx, fy});
        }
    }
    for (auto vi: vis) {
        for (auto vij: vi) cerr << vij;
        cerr << '\n';
    }
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == m and n == 3) {
        cout << 8;
        return 0;
    }
    if (min(n, m) >= 3 and max(n,m) > 3) {
        cout << n * m;
        return 0;
    }
    if (max(n ,m) < 3 or min(n , m ) < 2) {
        cout << 1;
        return 0;
    }
    assert(n == 2 or m == 2);
    if (n != 2) swap(n , m);
    assert(m >= 3);
    cout << (m + 3) / 4 + (m - 2 + 3) / 4;
    return 0;
}
