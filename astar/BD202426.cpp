#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // 21 = 1 + 4 + 16 = 2^0 + 2^2 + 2^4
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    vector<int> a(0), b(2), c(4);
    for (auto ch : s) {
        int x = (ch == '1');
        a.push_back(x);
        b.push_back(x);
        c.push_back(x);
    }
    vector<int> res;
    for (int i = 0, carry = 0; carry > 0 or i < n + 4; i ++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        if (i < c.size()) carry += c[i];
        res.push_back(carry % 2);
        carry /= 2;
    }
    reverse(res.begin(), res.end());
    for (auto i : res) cout << i;
    return 0;
}