#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 1; i + 1 < n; i += 2)
        swap(a[i], a[i + 1]);
    for (int i = 1; i + 1 < n; i ++) {
        if (a[i] > a[i + 1] and a[i] < a[i - 1]) {
            assert(false);
        }
        if (a[i] > a[i - 1] and a[i] < a[i + 1]) {
            assert(false);
        }
    }
    for (auto i: a)
        cout << i << " ";

    return 0;
}
