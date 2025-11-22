#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 1e9 + 7;

i64 power(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) res = res * x % mod;
    return res;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    i64 n, m, k, a = 0, b = 0, c = 0;
    cin >> n >> m >> k;
    for (int i = 0, x; i < n; i++) cin >> x, (a += x) %= mod;
    for (int i = 0, x; i < m; i++) cin >> x, (b += x) %= mod;
    for (int i = 0, x; i < k; i++) cin >> x, (c += x) %= mod;

    i64 res = 1;
    res = res * a % mod;
    res = res * b % mod;
    res = res * c % mod;
    res = res * power(n * m % mod * k % mod, mod - 2) % mod;
    cout << res;
    return 0;
}
