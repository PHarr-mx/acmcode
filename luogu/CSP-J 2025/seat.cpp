#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int N = n * m;
    vector<int> a(N);
    for (int i = 0; i < N; i ++) {
        cin >> a[i];
    }
    int rank = 1;
    for (int i = 1; i < N; i ++)
        if (a[i] > a[0]) rank ++;
    int i = 1, x = 1, y = 1;
    while (i < rank) {
        while (i < rank and y < n) {
            y ++;
            i ++;
        }
        if (i < rank and y == n) {
            i ++;
            x ++;
        }
        while (i < rank and y > 1) {
            i ++;
            y --;
        }
        if (i < rank and y == 1) {
            i ++;
            x ++;
        }
    }
    cout << x << " " << y;



    return 0;
}