#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<i64> p;
    for (int lst = -1, x; auto c: s) {
        x = c - '0';
        if (lst != x) p.push_back(0);

        p.back() += 1;
        lst = x;
    }
    i64 res = 0;
    k--;
    if ( k == 0) {
        for (auto i : p) {
            if (i > 1) res += i * (i - 1) / 2;
            res += i;
        }
    } else {
        for (int i = k; i < p.size(); i++) {
            res += p[i] * p[i - k];
        }
    }
    cout << res;
    return 0;
}
