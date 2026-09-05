#include <bits/stdc++.h>

using std::cin, std::cout;

using i64 = long long;

const int N = 5e4;
const i64 inf = LLONG_MAX / 2;

i64 square_pyramidal(i64 x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}

i64 f(i64 i, i64 m, i64 x) {
    if (i * i - x <= 0) return 0LL;
    return std::min(i64(std::sqrt(i * i - x )), m);
}

i64 c(i64 n, i64 m, i64 x) {
    i64 cnt = 0;
    for (i64 i = 1; i <= n; i ++)
        cnt += f(i, m, x);
    return cnt;
}

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 L = 1 - m * m, R = n * n - 1, res = -inf;
    while (L <= R) {
        i64 mid = (L + R) / 2;
        if (c(n, m, mid) >= k) res = mid, L = mid + 1;
        else R = mid - 1;
    }
    i64 ans = 0;
    for (i64 i = 1, j; i <= n; i ++) {
        j = f(i, m, res + 1);
        k -= j;
        ans += j * i * i - square_pyramidal(j);
    }
    ans += k * res;
    cout << ans << "\n";
}


int main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --) solve();
}