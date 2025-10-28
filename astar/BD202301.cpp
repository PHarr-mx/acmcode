#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const i64 inf = LLONG_MAX / 2;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int TE, FE, S;
    cin >> TE >> FE >> S;
    S = TE + FE - S;
    int T, F, N, M;
    cin >> T >> F >> N >> M;
    vector<vector<int> > e(N + 1);
    for (int i = 1, x, y; i <= M; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    auto dij = [&N, & e](int s) -> vector<i64> {
        vector<i64> dis(N + 1, inf);
        vector<int> vis(N + 1);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > heap;
        dis[s] = 0;
        heap.emplace(0, s);


        while (not heap.empty()) {
            auto [d, x] = heap.top();
            heap.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto y: e[x]) {
                if (dis[y] <= d + 1) continue;
                dis[y] = d + 1;
                heap.emplace(dis[y], y);
            }
        }

        return dis;
    };

    auto dis_t = dij(T);
    auto dis_f = dij(F);
    auto dis_n = dij(N);

    i64 res = inf;
    for (int i = 1; i <= N; i++) {
        if (max({dis_t[i], dis_f[i], dis_n[i]}) == inf) continue;
        res = min(res, dis_t[i] * TE + dis_f[i] * FE + dis_n[i] * S);
    }
    if (res == inf) cout << -1;
    else cout << res;
    return 0;
}
