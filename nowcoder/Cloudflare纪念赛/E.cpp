#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    vector<i64> f(n + 1);
    for (int i = 3; i <= n; i ++) {
        f[i] = max(f[i - 1], f[i - 3] + a[i - 1]);
    }
    cout << f[n];
    return 0;
}
