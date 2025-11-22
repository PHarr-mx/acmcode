#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 1e6;
    vector<int> e(N + 1);
    for (int i = 1; i <= N; i++)
        e[i] = (i / 2) + e[i / 2];


    auto power = [](i64 x, int y) {
        i64 res = 1;
        for (; y; y /= 2, x = x * x % mod)
            if (y & 1) res = res * x % mod;
        return res;
    };
    auto inv = [&power](int x) {
        return power(x, mod - 2);
    };
    int T;
    cin >> T;
    for (int x; T; T--) {
        cin >> x;
        cout << inv(e[x] + 1) << ' ';
    }

    return 0;
}
