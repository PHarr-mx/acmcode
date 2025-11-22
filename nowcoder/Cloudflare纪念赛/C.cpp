#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    if (n & 1) {
        cout << -1;
        return 0;
    }
    string s;
    cin >> s;
    int cnt = 0, res = 0;
    for (auto c: s) {
        if (c == '(') cnt ++;
        else cnt --;
        while (cnt < 0) cnt += 2, res ++;
    }
    cout << res + cnt / 2;
    return 0;
}
