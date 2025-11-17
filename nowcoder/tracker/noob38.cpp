#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) continue;
        if (to_string(i).find('4') != string::npos) continue;
        cout << i << '\n';
    }
    return 0;
}
