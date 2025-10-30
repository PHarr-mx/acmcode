#include <bits/stdc++.h>

using namespace std;


int main() {
    double xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;
    double d1 = abs(xa - xb) + abs(ya - yb);
    double d2 = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    cout << fixed << setprecision(10) << abs(d1 - d2);
    return 0;
}
