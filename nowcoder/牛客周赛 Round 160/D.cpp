#include <bits/stdc++.h>

using std::cin, std::cout;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    i64 n, p;
    cin >> n;
    i64 res = 0;
    while (n) {
        p = n >> 1;
        res += p * 2;
        if (n & 1) res += 1;
        n = p;
    }
    cout << res;
    return 0;
}