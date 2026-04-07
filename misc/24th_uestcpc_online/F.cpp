#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int inf = INT_MAX / 2;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    i64 n;
    cin >> n;
    vector<i64> a(n);
    int sum_xor = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum_xor ^= a[i];
    }
    if (sum_xor == 0) {
        cout << "Yes\n";
        return 0;
    }
    if (n % 2 == 0) {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}