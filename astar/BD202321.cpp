#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int,vector<int>> cnt;
    for (int i = 1, p; i <= n; i ++) {
        cin >> p;
        cnt[p].push_back(i);
    }
    auto check = [&k](vector<int> v) {
        for (int i = 1; i < v.size(); i ++)
            if (v[i] - v[i - 1] <= k) return true;
        return false;
    };
    int res = 0;
    for (auto [k, v] : cnt)
        if (check(v)) res ^= k;
    cout << res;
    return 0;
}