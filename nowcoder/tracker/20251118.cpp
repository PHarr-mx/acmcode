#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int inf = INT_MAX / 2;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<vector<int>> arr;
    do {
        arr.push_back(a);
    }while (next_permutation(a.begin(), a.end()));

    while (k --) {
        char c;
        cin >> c;
        if (c == 'P') {
            int x;
            cin >> x;
            x --;
            for (auto i : arr[x]) cout << i << " ";
            cout << "\n";
        } else {
            for (auto &i : a) cin >> i;
            cout << lower_bound(arr.begin(), arr.end(), a) - arr.begin() + 1 << "\n";
        }
    }
    return 0;
}
