#include <bits/stdc++.h>
using i64 = long long;

i64 dp[3002][3002];
int match[3002];
i64 w[3002];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int m = 2 * n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r >> w[l];
        match[l] = r, match[r] = l;
    }
    for (int i = m; i >= 1; --i)
        for (int j = i; j <= m; ++j) {
            dp[i][j] = dp[i + 1][j];
            int k = match[i];
            if (k > i && k <= j)
                dp[i][j] = std::max(dp[i][j], w[i] + dp[i + 1][k - 1] + dp[k + 1][j]);
        }
    std::cout << dp[1][m] << "\n";
}