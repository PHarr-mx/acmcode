#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    stack<pii> stk;
    int ans = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        while (not stk.empty() and stk.top().first <= x) {
            ans ^= stk.top().second;
            stk.pop();
        }
        stk.emplace(x, i);
        ans ^= i;
        cout << ans << "\n";
    }

    return 0;
}
