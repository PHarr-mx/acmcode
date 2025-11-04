#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
using i64 = long long;

void solve1(vector<int> &len) {
    sort(len.begin(), len.end());
    cout << (len[0] + len[1] > len[2]);
}

void solve2(i64 n) {
    i64 res = 1;
    for (int i = 0; i < n; i++)
        res = res * 2 % mod;
    i64 selected_0 = 1;
    i64 selected_1 = n;
    i64 selected_2 = (n * (n - 1) / 2) % mod;
    res = (res - selected_0 + mod) % mod;
    res = (res - selected_1 + mod) % mod;
    res = (res - selected_2 + mod) % mod;
    cout << res;
}

void solve3(int n, vector<int> &len) {
    int res = 0;
    for (int i = 0, N = (1 << n), sum_len, max_len; i < N; i++) {
        if (__builtin_popcount(i) < 3) continue;
        sum_len = 0, max_len = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum_len += len[j];
                max_len = max(max_len, len[j]);
            }
        }
        if (sum_len > max_len * 2) res++;
    }
    cout << res % mod;
}


void solve4(i64 n, vector<int> &a) {
    sort(a.begin(), a.end());
    int res = 0;
    const int N = 5000;
    vector<i64> f(N + 1);
    vector<i64> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i ++) pow2[i] = pow2[i - 1] * 2 % mod;
    f[0] = 1;
    for (int i = 0, sum; i < n; i++) {
        sum = 0;
        for (int j = 0; j <= a[i]; j++)
            sum = (sum + f[j]) % mod;

        res = (res + pow2[i] - sum + mod) % mod;

        for (int j = N; j >= a[i]; j--)
            f[j] = (f[j] + f[j - a[i]]) % mod;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> len(n);
    for (auto &i: len) cin >> i;

    bool flag = true;
    for (auto i: len) {
        flag &= (i == 1);
    }

    if (n == 3) {
        solve1(len);
    } else if (flag) {
        solve2(n);
    } else if (n <= 20) {
        solve3(n, len);
    } else {
        solve4(n, len);
    }

    return 0;
}
