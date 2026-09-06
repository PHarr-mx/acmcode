#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n;
    i64 t;
    std::cin >> n >> t;

    std::vector<i64> l(n), r(n);
    std::unordered_map<i64, std::vector<i64>> byL, byR;
    std::vector<i64> outL;                          // 长度为 t 的弦的左端点
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
        byL[l[i]].push_back(r[i]);
        byR[r[i]].push_back(l[i]);
        if (r[i] - l[i] == t) outL.push_back(l[i]);
    }
    for (auto &kv : byL) std::sort(kv.second.begin(), kv.second.end());
    for (auto &kv : byR) std::sort(kv.second.begin(), kv.second.end());
    std::sort(outL.begin(), outL.end());

    i64 ans = 0;

    for (int j = 0; j < n; ++j) {
        i64 L = r[j] - t;
        if (L < 0 || L >= l[j]) continue;
        auto it = byL.find(L);
        if (it == byL.end()) continue;
        auto &v = it->second;
        ans += std::lower_bound(v.begin(), v.end(), r[j]) -
               std::lower_bound(v.begin(), v.end(), l[j]);
    }

    for (auto &kv : byL) {
        i64 M = kv.first + t;
        auto &v = kv.second;
        i64 s = std::upper_bound(v.begin(), v.end(), M) - v.begin();
        i64 c = s - (std::lower_bound(v.begin(), v.end(), M) - v.begin());
        ans += s * (s - 1) / 2 - (s - c) * (s - c - 1) / 2;
    }

    for (auto &kv : byR) {
        i64 m = kv.first - t;
        auto &v = kv.second;
        i64 g = v.end() - std::lower_bound(v.begin(), v.end(), m) -
                (std::upper_bound(v.begin(), v.end(), m) - std::lower_bound(v.begin(), v.end(), m));
        i64 c = std::upper_bound(v.begin(), v.end(), m) -
                std::lower_bound(v.begin(), v.end(), m);
        ans += c * g;
    }

    for (int i = 0; i < n; ++i) {
        i64 lo = r[i] - t;
        if (lo >= l[i]) continue;
        ans += std::lower_bound(outL.begin(), outL.end(), l[i]) -
               std::upper_bound(outL.begin(), outL.end(), lo);
    }

    std::cout << ans << "\n";
    return 0;
}