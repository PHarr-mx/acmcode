#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

const int mod = 1e9 + 7;
const int inf = LLONG_MAX / 2;

struct BinaryIndexedTree {
#define lowbit(x) ( x & -x )
    int n, bN;
    vector<int> b;

    BinaryIndexedTree(int n) : n(n), b(n + 1, 0) {
        bN = n;
        while (bN != lowbit(bN)) bN -= lowbit(bN);
    };

    void add(int i, int y) {
        for (; i <= n; i += lowbit(i)) b[i] += y;
        return;
    }

    int calc(int i) {
        int sum = 0;
        for (; i; i -= lowbit(i)) sum += b[i];
        return sum;
    }

    int find(int val) {
        if (calc(n) < val) return -1;
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (calc(mid) >= val) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    i64 n, hp;
    cin >> n >> hp;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> idp(n + 1);
    iota(idp.begin(), idp.end(), 0);
    sort(idp.begin() + 1, idp.end(), [&](int x, int y) {
        if (a[x] != a[y]) return a[x] > a[y];
        return x < y;
    });
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i ++)
        idx[idp[i]] = i;
    BinaryIndexedTree pre(n), cnt(n);
    int res = inf;
    for (int i = 1, k; i <= n and i <= res; i++) {
        hp -= a[i];
        if (hp <= 0) {
            res = min(res, i);
            break;
        }
        pre.add(idx[i], a[i]);
        cnt.add(idx[i], 1);
        k = pre.find(hp);
        if (k < 0) continue;
        res = min(res, i + cnt.calc(k));
    }
    if (res == inf) res = -1;
    cout << res;


    return 0;
}
