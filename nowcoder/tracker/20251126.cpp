#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

// #define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<vector<int> > f(a + 1, vector<int>(b + 1, 0));
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == 0 and j == 0) continue;
            if (i == 0 or j == 0)
                f[i][j] = (i + j + max(x, y) - 1) / max(x, y);
            f[i][j] = min({
                f[max(i - x, 0)][j] + 1,
                f[i][max(j - x, 0)] + 1,
                f[max(i - y, 0)][max(j - y, 0)] + 1,
            });
            cerr << i << " , " << j << " " << f[i][j] << "\n";
        }
    }
    cout << f[a][b];
    return 0;
}
