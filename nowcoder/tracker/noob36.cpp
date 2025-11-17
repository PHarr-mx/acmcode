#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> f(n + 1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i ++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
    return 0;
}
