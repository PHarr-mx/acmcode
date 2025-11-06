#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<i64> > a(n + 1, vector<i64>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];
            a[i][j] += a[i][j - 1];
            a[i][j] -= a[i - 1][j - 1];
        }
    for (int ax, ay, bx, by; q; q--) {
        cin >> ax >> ay >> bx >> by;
        cout << a[bx][by] - a[ax - 1][by] - a[bx][ay - 1] + a[ax - 1][ay - 1] << "\n";
    }
    return 0;
}
