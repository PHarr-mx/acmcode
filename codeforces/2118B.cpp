#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i ++) {
        if (i > 1) ans.push_back({i, 1, i});
        if (i + 1 < n) ans.push_back({i, i + 1 , n});
    }
    cout << ans.size() << '\n';
    for (const auto &v : ans) {
        for (const auto &i : v) cout << i << ' ';
        cout << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --)
        solve();
}

// 对于一个数组，两次翻转，可以得到逆序数组的任意循环位移
// 方法就是第i翻转前i个和后n-i个
// 1 4 3 2
// 2 1 4 3
// 3 2 1 4
// 4 3 2 1