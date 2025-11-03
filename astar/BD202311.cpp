#include <bits/stdc++.h>

using namespace std;

const int V = 1e6;
const int inf = INT_MAX / 2;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> lst(V + 1, -1);
    vector<int> nxt(n + 1, -1);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (lst[x] != -1)
            nxt[lst[x]] = i;
        lst[x] = i;
    }

    vector<int> dis(n + 1, inf);
    vector<int> vis(n + 1, 0);
    dis[1] = 0;
    queue<int> que;
    que.push(1);
    while (not que.empty()) {
        int x = que.front();
        que.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        if (x - 1 >= 1 and dis[x - 1] > dis[x] + 1) {
            dis[x - 1] = dis[x] + 1;
            que.push(x - 1);
        }
        if (x + 1 <= n and dis[x + 1] > dis[x] + 1) {
            dis[x + 1] = dis[x] + 1;
            que.push(x + 1);
        }
        if (nxt[x] != -1 and dis[nxt[x]] > dis[x] + 1) {
            dis[nxt[x]] = dis[x] + 1;
            que.push(nxt[x]);
        }
    }
    cout << dis[n] << "\n";
    return 0;
}
