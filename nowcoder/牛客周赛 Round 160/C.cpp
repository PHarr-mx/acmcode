#include <bits/stdc++.h>

using std::cin, std::cout;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 x;
    cin >> x;
    i64 r = std::sqrt(x);
    while (r * r > x) r--;
    while ((r + 1) * (r + 1) <= x)  r++;
    cout << r << " " << x - r * r << " " << (r + 1) * (r + 1) - x << "\n";

}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T --)
        solve();
    return 0;
}