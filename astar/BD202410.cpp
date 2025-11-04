#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0, l, r; i < k; i++) {
        cin >> l >> r;
        p[l - 1]++;
        if (r < n)p[r]--;
    }
    for (int i = 1; i < n; i ++) {
        p[i] += p[i - 1];
    }
    sort(p.begin(), p.end());
    cout << p[n / 2];

}
