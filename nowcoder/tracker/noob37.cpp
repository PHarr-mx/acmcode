#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x;
    cin >> x;
    x = abs(x);
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    cout << res;
    return 0;
}
