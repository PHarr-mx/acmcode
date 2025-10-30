#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int inf = INT_MAX / 2;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> b;
    int ans = 0;

    for (int i = 0, lst = -1, cnt = 0; i < n; i++) {
        cin >> a[i];
        b.insert(a[i]);
        if (a[i] == lst) cnt++;
        else lst = a[i], cnt = 1;
        ans = max(ans, cnt);
    }
    int res = ans;
    for (auto x: b) {
        for (int i = 0, lst = -1, cnt = 0; i < n; i++) {
            if (a[i] == x) continue;
            if (a[i] == lst) cnt++;
            else lst = a[i], cnt = 1;
            res = max(res, cnt);
        }
    }
    cout << res - ans;

    return 0;
}
