#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = n, x, t; i >= 1; i--) {
        x = 0, t = 1;
        while (t < i) {
            x++;
            t <<= 1;
        }
        if (x <= k) {
            k -= x;
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    if (k > 0) {
        cout << "-1\n";
        return 0;
    }
    for (auto i: a) cout << i << " ";
    reverse(b.begin(), b.end());
    for (auto i: b) cout << i << " ";

    return 0;
}
