#include <bits/stdc++.h>


void solve() {
    int x;
    std::cin >> x;
    std::cout << (x + 1) % 3 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T --)
        solve();
    return 0;
}