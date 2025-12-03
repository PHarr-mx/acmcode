#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

// #define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string A;
    cin >> A;
    i64 b;
    cin >> b;
    i64 a = 0;
    for (auto c : A )
        a = (a * 10 + c - '0') % b;
    cout << gcd(a, b);
    return 0;
}
