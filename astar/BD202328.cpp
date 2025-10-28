#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    vector<int> vis(n + 1);
    queue<int> q;
    for (int i = 1, t; i <= n; i ++) {
        cin >> t;
        if (t != 0) e[t].push_back(i);
        else {
            vis[i] = 1;
            q.push(i);
        }
    }
    while (not q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : e[x]) {
            if (vis[y]) continue;
            vis[y] = 1;
            q.push(y);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        if (vis[i]) ans ^= i;
    cout << ans;
    return 0;
}
