#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> cnt(10);

    for (auto c : s) {
        if (c < '0' or c > '9') continue;
        cnt[c - '0'] += 1;
    }

    for (int i = 9; i >= 0; i --) {
        while (cnt[i] > 0) {
            cout << i;
            cnt[i] --;
        }
    }

    return 0;
}