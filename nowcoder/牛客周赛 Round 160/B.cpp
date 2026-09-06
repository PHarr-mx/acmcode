#include <bits/stdc++.h>

using std::cin, std::cout;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    u64 x, k;
    cin >> x >> k;
    k %= 4;
    while (k --) {
        x = ((x & 7) << 1) | ((x >> 3) & 1);
    }
    cout << x << " " << std::popcount(x) << "\n";

}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T --)
        solve();
    return 0;
}