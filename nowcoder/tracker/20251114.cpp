#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const i64 mod = 1e9 + 7;
    const int N = 5e5;
    vector<i64> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % mod;
    auto power = [&mod](i64 x, int y) {
        i64 ans = 1;
        for (; y; y >>= 1, x = x * x % mod)
            if (y & 1) ans = ans * x % mod;
        return ans;
    };
    auto inv = [&mod, &power](i64 x) {
        return power(x, mod - 2);
    };
    vector<i64> inv_fact(N + 1);
    inv_fact[N] = inv(fact[N]);
    for (int i = N; i >= 1; i--)
        inv_fact[i - 1] = inv_fact[i] * i % mod;

    auto C = [&mod, &fact, &inv_fact](i64 x, i64 y) {
        return fact[x] * inv_fact[y] % mod * inv_fact[x - y] % mod;
    };
    int t;
    cin >> t;
    for (int x, y; t; t--) {
        cin >> y >> x;
        cout << C(x, y) << '\n';
    }
    return 0;
}
