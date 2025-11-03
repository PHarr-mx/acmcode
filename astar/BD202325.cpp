#include <bits/stdc++.h>

using namespace std;

const int V = 1e6;
const int inf = INT_MAX / 2;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1, vector<int>(m + 1));
    int sx = -1, sy = -1;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '#') g[i][j] = 1;
            if (s[j - 1] == 'S') sx = i, sy = j;
        }
    }
    assert(sx != -1 || sy != -1);
    vector<vector<int> > preX(n + 1, vector<int>(m + 1));
    vector<vector<int> > preY(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            preX[i][j] = preX[i][j - 1] + g[i][j];
            preY[i][j] = preY[i - 1][j] + g[i][j];
        }
    }


    auto checkX = [&preX](int x, int ya, int yb) {
        assert(ya != yb);
        if (ya > yb) swap(ya, yb);
        return preX[x][yb] == preX[x][ya - 1];
    };
    auto checkY = [&preY](int y, int xa, int xb) {
        assert(xa != xb);
        if (xa > xb) swap(xa, xb);
        return preY[xb][y] == preY[xa - 1][y];
    };

    int al = sy, ar = sy;
    while (al - 1 >= 1 and g[sx][al - 1] == 0) al--;
    while (ar + 1 <= m and g[sx][ar + 1] == 0) ar++;
    for (int bx = 1; bx <= n and al < ar; bx++) {
        if (bx == sx) continue;
        if (g[bx][sy]) continue;
        int bl = sy, br = sy;
        while (bl - 1 >= 1 and g[bx][bl - 1] == 0) bl--;
        while (br + 1 <= m and g[bx][br + 1] == 0) br++;
        int l = max(al, bl), r = min(ar, br);
        if (l == r) continue;
        int fl = -1, fr = -1;
        for (int y = l; y <= r; y++) {
            if (checkY(y, sx, bx)) {
                if (fl == -1) fl = y;
                fr = y;
            }
        }
        if (fl < fr and fl <= sy and sy <= fr) {
            cout << "Yes\n";
            return 0;
        }
    }

    int au = sx, ad = sx;
    while (au - 1 >= 1 and g[au - 1][sy] == 0) au--;
    while (ad + 1 <= n and g[ad + 1][sy] == 0) ad++;
    for (int by = 1; by <= m and au < ad; by++) {
        if (sy == by) continue;
        if (g[sx][by]) continue;
        int bu = sx, bd = sx;
        while (bu - 1 >= 1 and g[bu - 1][by] == 0) bu--;
        while (bd + 1 <= n and g[bd + 1][by] == 0) bd++;
        int u = max(au, bu), d = min(ad, bd);
        if (u == d) continue;
        int fu = -1, fd = -1;
        for (int x = u; x <= d; x++) {
            if (checkX(x, sy, by)) {
                if (fu == -1) fu = x;
                fd = x;
            }
        }
        if (fu < fd and fu <= sx and sx <= fd) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
