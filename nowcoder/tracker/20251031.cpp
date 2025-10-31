#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int inf = INT_MAX / 2;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> v(max(a.size(), b.size()));
    for (int i = 0; i < v.size(); i++) {
        if (i < a.size()) v[i] += a[i] - '0';
        if (i < b.size()) v[i] += b[i] - '0';
        v[i] %= 10;
    }
    while (v.size() > 1 and v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());
    for (auto i: v) cout << i;
    return 0;
}
