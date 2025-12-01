#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

// #define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i == j) * k << " ";
        }
        cout << "\n";
    }
    return 0;
}
