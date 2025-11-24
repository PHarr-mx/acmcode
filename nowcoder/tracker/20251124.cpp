#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int inf = INT_MAX / 2;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> H(n + 1), V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> H[i] >> V[i];
    vector<int> cnt(n + 1);
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (not stk.empty() and H[stk.top()] <= H[i]) stk.pop();
        if (not stk.empty()) cnt[stk.top()] += V[i];
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n; i >= 1; i--) {
        while (not stk.empty() and H[stk.top()] <= H[i]) stk.pop();
        if (not stk.empty()) cnt[stk.top()] += V[i];
        stk.push(i);
    }
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
    return 0;
}