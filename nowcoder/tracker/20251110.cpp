#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    map<string, int> cnt;
    while (cin >> s)
        cnt[s]++;
    vector<pair<int, string> > res;
    for (auto [k, v]: cnt) {
        if (v < 3) continue;
        res.emplace_back(v, k);
    }
    sort(res.begin(), res.end(),[&](auto &x, auto &y) {
        if (x.first != y.first) return x.first > y.first;
        else return x.second < y.second;
    });
    for (auto [k, v]: res)
        cout << v << '\n';
    return 0;
}
