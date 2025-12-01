#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using Con = vector<pii>;

const int inf = INT_MAX / 2;
const vector<pii> d = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int cnt = 0;

    Con connected;
    for (int i = 0; i < n and cnt < 2; i++) {
        for (int j = 0; j < m and cnt < 2; j++) {
            if (g[i][j] == 0)
                continue;
            cnt++;
            queue<pii> q;
            q.emplace(i, j);
            while (not q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (g[x][y] != 1)
                    continue;
                g[x][y] = 0;
                connected.emplace_back(x, y);
                for (auto [dx, dy] : d) {
                    int fx = x + dx, fy = y + dy;
                    if (fx < 0 or fy < 0 or fx >= n or fy >= m)
                        continue;
                    if (g[fx][fy] != 1)
                        continue;
                    q.emplace(fx, fy);
                }
            }
        }
    }
    if (cnt >= 2) {
        cout << "-1\n";
        return;
    }
    if (connected.size() == 0) {
        if (k == 0) {
            cout << "0\n";
            return;
        }
        connected.emplace_back(0, 0);
        k -= 1;
    }
    auto normal = [](Con &con) -> void {
        sort(con.begin(), con.end());
        auto [x0, y0] = con[0];
        for (auto &[x, y] : con)
            x -= x0, y -= y0;
        return;
    };

    auto rotate = [](Con &con) -> void {
        for (auto &[x, y] : con) {
            swap(x, y);
            y = -y;
        }
        return;
    };

    auto flip_x = [](Con &con) -> void {
        for (auto &[x, y] : con) {
            x = -x;
        }
        return;
    };
    auto flip_y = [](Con &con) -> void {
        for (auto &[x, y] : con) {
            y = -y;
        }
        return;
    };
    auto check_xy = [&n, &m](Con &con) -> bool {
        int max_x = -inf, max_y = -inf, min_x = inf, min_y = inf;
        for (auto &[x, y] : con) {
            max_x = max(max_x, x);
            max_y = max(max_y, y);
            min_x = min(min_x, x);
            min_y = min(min_y, y);
        }
        int dx = max_x - min_x;
        int dy = max_y - min_y;
        return (dx < n and dy < m) or (dy < n and dx < m);
    };
    set<Con> vis;
    auto append_other = [&vis, &normal, &rotate, &flip_x,
                         &flip_y](Con con) -> void {
        for (int i = 0; i < 3; i++) {
            rotate(con), normal(con), vis.insert(con);
            flip_x(con), normal(con), vis.insert(con);
            flip_y(con), normal(con), vis.insert(con);
            flip_x(con), normal(con), vis.insert(con);
            flip_y(con);
        }
    };
    normal(connected);
    vis.insert(connected);
    append_other(connected);
    int res = 1;
    auto dfs = [&vis, &append_other, &normal, &res,
                &check_xy](auto &&self, Con con, int k) -> void {
        if (k == 0)
            return;
        for (const auto &[x, y] : con) {
            for (const auto [dx, dy] : d) {
                int fx = x + dx, fy = y + dy;
                Con new_con = con;
                new_con.emplace_back(fx, fy);
                normal(new_con);

                if (not check_xy(new_con))
                    continue;
                bool flag = true;
                for (int i = 1; i < new_con.size(); i++) {
                    if (new_con[i] == new_con[i - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (not flag)
                    continue;
                if (vis.insert(new_con).second == false)
                    continue;
                append_other(new_con);
                res++;
                self(self, new_con, k - 1);
            }
        }
    };
    dfs(dfs, connected, k);
    cout << res << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
