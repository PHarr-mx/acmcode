#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    int res = 0;
    for (int i = 1; i <= n; i ++)
        if (a[i] == b[i]) res = i;
    vector<int> vis_a(n + 1, -1);
    vector<int> vis_b(n + 1, -1);

    for (int i = n; i >= 1; i --) {
        if (vis_a[a[i]] == -1) vis_a[a[i]] = i;
        else res =  max(res, i); // a[i] 在 i 的左侧出现过，则一定可以把 b[i] 变成 a[i]
        if (vis_a[b[i]] > i + 1) res = max(res, i); // b[i] 在 i 的左侧出现过且不相邻，则一定可以把a[i]变成b[i]

        if (vis_b[b[i]] == -1) vis_b[b[i]] = i;
        else res = max(res, i);
        if (vis_b[a[i]] > i + 1) res = max(res, i);

        if (a[i] == b[i]) res = max(res, i);
    }
    cout << res << '\n';
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