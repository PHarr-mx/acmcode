#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    int res = 0;
    auto check_symmetry = [&](int x) {
        string p = to_string(x), q = p;
        reverse(q.begin(), q.end());
        return p == q;
    };
    auto check_date = [&](int x) {
        int d = x % 100;
        x /= 100;
        int m = x % 100;
        x /= 100;
        int y = x;
        if (d < 1 or d > 31) return false;
        if (m < 1 or m > 12) return false;
        if (m == 2) {
            if (d > 29) return false;
            if (not((y % 400 == 0) or (y % 4 == 0 && y % 100 != 0)))
                if (d > 28) return false;
        } else if (not(m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12))
            if (d > 30) return false;
        return true;
    };
    for (int i = l; i <= r; i++) {
        if (i % 100 > 31) {
            i -= i % 100;
            i += 100;
        }
        if (i % 10000 > 1231) {
            i -= i % 10000;
            i += 10000;
        }
        if (not check_symmetry(i)) continue;
        if (not check_date(i)) continue;
        res++;
    }
    cout << res;
    return 0;
}
