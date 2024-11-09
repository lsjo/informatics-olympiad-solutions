#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);

    int n, m;
    long long mid;
    long long ans = 0;
    long long num = 0;
    cin >> n;

    long long A[n];
    long long totaldiffs[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> m;
        num += A[i] - m;
        totaldiffs[i] = num;
    }

    sort(totaldiffs, totaldiffs+n);
    mid = totaldiffs[(n-1) / 2];

    for (int i = 0; i < n; i++) {
        ans += abs(totaldiffs[i] - mid);
    }

    cout << ans;
    return 0;
}
