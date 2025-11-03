#include <bits/stdc++.h>

using namespace std;

const int V = 1e6;
const int inf = INT_MAX / 2;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> p(n + 1);
    vector<int> v(n + 1);
    for (int i = 2; i <= n; i++) {
        if (v[i]) continue;
        for (int j = i; j <= n; j += i) {
            v[j] = 1;
            for (int x = j; x % i == 0; x /= i) {
                p[i] += n - j + 1;
            }
        }
    }
    cout << "f(" << n << ")=";
    bool f = 0;
    for (int i = 0; i <= n; i++) {
        if (p[i] == 0) continue;
        if (f) cout << "*";
        cout << i;
        if (p[i] > 1) cout << "^" << p[i];
        f = 1;
    }

    return 0;
}
