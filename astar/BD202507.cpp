#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 1, p; i <= n; i ++) {
        cin >> p;
        s = max(s, (s + p + 1) / 2);
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --) solve();
    return 0;
}
