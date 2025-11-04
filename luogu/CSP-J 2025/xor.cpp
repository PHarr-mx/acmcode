#include<bits/stdc++.h>

using namespace std;


const int V = 1 << 20;

void solve1(int n, int k, vector<int> &a) {
    // 111111111
    // 11 11 11 11
    cout << n / 2 << "\n";
    return ;
}

void solve2(int n, int k, vector<int> &a) {
    // k = 0 and a < 1
    // 0011 -> 0, 0, 11
    // 00111 -> 0, 0, 11
    // 101 -> 101 / 0
    // 1001 -> 1001 / 0, 0
    // 0 必须单独一组，会剩下若干个连续 1，可以使用 solve1 解决
    int res = 0, cnt = 0; // cnt 是当前连续 1 的个数
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 0) {
            res ++;
            res += cnt / 2;
            cnt = 0;
        }
        else {
            cnt ++;
        }
    }
    res += cnt / 2;
    cout << res << "\n";
    return ;
}

void solve3(int n, int k, vector<int> &a) {
    // 111 -> 1, 1, 1
    // 100 -> 1 / 10 / 100
    // 1001 -> 1, 1 / 10, 1 / 1, 01 / 10, 01
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        res += a[i];
    }
    cout << res << "\n";
    return;
}

void solve4(int n, int k, vector<int> &a) {
    vector<int> f(n + 1);
    vector<int> lst(V + 1, - 1);
    lst[0] = 0;
    for (int i = 1, pre = 0; i <= n; i ++) {
        pre ^= a[i];
        f[i] = f[i - 1];
        if (lst[pre ^ k] != -1 )f[i] = max(f[i], f[lst[pre ^ k]] + 1);
        lst[pre] = i;
    }
    cout << f[n] << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    bool flagA = true;
    bool flagB = true;
    for (int i = 1; i <= n; i ++) {
        if (a[i] != 1) flagA = false;
        if (a[i] > 1) flagB = false;
    }

    if (k == 0 and flagA) {
        solve1(n, k, a);
        return 0;
    } else if (k == 0 and flagB) {
        solve2(n, k, a);
    } else if (k == 1 and flagB) {
        solve3(n, k, a);
    } else {
        solve4(n, k, a);
    }



    return 0;
}