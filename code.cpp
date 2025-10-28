#include <bits/stdc++.h>

using namespace std;

long long f(long long n) {
    if (n < 20180001) return n + 2017;
    return f(f(n - 2018));
}

int main() {
    long long n;
    cin >> n;

    long long t = 2018LL << 30;
    long long p = 20180001 + 2018 * 3;
    while (t >= 2018) {
        while (n - t > p)
            n -= t;
        cerr << n << " " << t << endl;
        t /= 2;
    }
    cerr << n << "\n";
    cout << f(n) << endl;
    return 0;
}
