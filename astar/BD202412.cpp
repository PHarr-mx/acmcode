#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int res = 0, a = 0, b = 0;
    if (count(s.begin(), s.end(), ')') * 2 > s.size()) {
        reverse(s.begin(), s.end());
        for (auto &c: s)
            c = c == '(' ? ')' : '(';
    }

    for (auto c: s) {
        if (c == '(') a++;
        else b++;

        if (c == '(' and a - 2 >= b) res++;
        if (a - 2 < b) res = 0;
    }
    cout << res;
    return 0;
}
