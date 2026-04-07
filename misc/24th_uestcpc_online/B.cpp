#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), w(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i] >> b[i] >> c[i] >> w[i];
    int A, B, C;
    cin >> A >> B >> C;
    vector f(A + 1, vector(B + 1, vector(C + 1, inf)));
    f[0][0][0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int pa = a[i] ; pa <= A; pa ++)
            for (int pb = b[i]; pb <= B; pb ++)
                for (int pc = c[i]; pc <= C; pc ++)
                    f[pa][pb][pc] = min(f[pa][pb][pc], f[pa - a[i]][pb - b[i]][pc - c[i]] + w[i]);
    }
    if (f[A][B][C] == inf) {
        cout << "-1\n";
    } else {
        cout << f[A][B][C] << '\n';
    }
    return 0;
}