#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int res = 0;
    do {
        bool ok = true;
        for (int i = 1; i < s.size() and ok; ++i)
            if (s[i] == s[i - 1]) ok = false;
        if (ok) res++;
    } while (next_permutation(s.begin(), s.end()));
    cout << res;
    return 0;
}
