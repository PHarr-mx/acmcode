#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int inf = INT_MAX / 2;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    string s;
    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i ++) {
        cin >> s;
        for (int j = 1; j <= m; j ++)
            v[i][j] = (s[j - 1] == '*');
    }

    queue<pii> que;
    que.emplace(0, 0);

    while (not que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        if (v[x][y]) continue;
        v[x][y] = 1;
        for (int i = 0, fx, fy; i < 4; i ++) {
            fx = x + dx[i], fy = y + dy[i];
            if (fx < 0 or fy < 0 or fx > n + 1 or fy > m + 1) continue;
            if (v[fx][fy]) continue;
            que.emplace(fx, fy);
        }
    }
    int res = 0;
    for (const auto &vi: v)
        for (const auto &vij: vi)
            res += vij == 0;
    cout << res;

    return 0;
}
