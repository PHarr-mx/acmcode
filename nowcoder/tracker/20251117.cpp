#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int inf = INT_MAX / 2;

void solve() {
    int r, c;
    cin >> r >> c;
    pair<int, int> start;
    cin >> start.first >> start.second;
    int n;
    cin >> n;
    vector<pair<int, int> > nodes(n);
    for (auto &[x, y]: nodes)
        cin >> x >> y;

    auto dis = [](pair<int, int> x, pair<int, int> y) -> int {
        return abs(x.first - y.first) + abs(x.second - y.second);
    };
    int res = inf;
    vector<int> f(n);
    sort(nodes.begin(), nodes.end());
    do {
        int ans = 0;
        auto lst = start;
        for (auto &p: nodes) {
            ans += dis(lst, p);
            lst = p;
        }
        ans += dis(lst, start);
        res = min(res, ans);
    } while (next_permutation(nodes.begin(), nodes.end()));
    cout << "The shortest path has length " << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
