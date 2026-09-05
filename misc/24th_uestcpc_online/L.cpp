#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 mod = 998244353;

i64 power(i64 x, i64 y) {
    i64 ans = 1;
    for (; y > 0; y >>= 1, x = (x * x) % mod)
        if (y & 1) ans = (ans * x) % mod;
    return ans;
}

i64 inv(i64 x) {
    return power(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    i64 n, a, b, y, p, q;
    cin >> n >> a >> b >> y >> p >> q;
    const i64 k = a * inv(b) % mod;
    const i64 r = p * inv(q) % mod;
    i64 E = 0;
    for (int i = 0; i < n; i ++)
        E = (E * k % mod + y) * r % mod;
    cout << E;
    return 0;
}
