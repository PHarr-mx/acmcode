#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    int n, f;
    string s;
    while (T--) {
        cin >> n >> s;
        map<char, int> cnt;
        for (auto c: s) cnt[c]++;
        if (cnt['L'] == 0 and cnt['R'] == 0) {
            cout << max(cnt['U'], cnt['D']) + 1 << '\n';
        } else if (cnt['U'] == 0 and cnt['D'] == 0) {
            cout << max(cnt['L'], cnt['R']) + 1 << '\n';
        } else if (cnt['L'] == cnt['R'] and cnt['U'] == cnt['D']) {
            cout << n << '\n';
        } else {
            cout << n + 1 << '\n';
        }
    }
    return 0;
}
