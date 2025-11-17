#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        res += sum;
    }
    cout << res;

    return 0;
}
