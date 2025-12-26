#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    int al = ((l - 1 + 2) / 3) * 3 + 1;
    int bl, cl;
    if (al - 1 >= l) cl = al - 1;
    else cl = al + 2;

    if (al - 2 >= l) bl = al - 2;
    else bl = al + 1;

    int ax = (r - al + 3) / 3;
    int bx = (r - bl + 3) / 3;
    int cx = (r - cl + 3) / 3;
    cout << ax << ' ' << bx << ' ' << cx;
    return 0;
}
