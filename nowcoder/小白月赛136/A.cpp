#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int a, b, c, ax, ay, az, bx, by, bz;
    cin >> a >> b >> c;
    if (a != 0) ax = 0, bx = a * 2;
    else ax = 1, bx = -1;

    if (b != 0) ay = 0, by = b * 2;
    else ay = 1, by = -1;

    if (c != 0) az = 0, bz = c * 2;
    else az = 1, bz = -1;

    cout << ax << " " << ay << " " << az << " " << bx << " " << by << " " << bz << "\n";
    return 0;
}