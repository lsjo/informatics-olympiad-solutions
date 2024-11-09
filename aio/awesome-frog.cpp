#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("frogin.txt", "r", stdin);
    freopen("frogout.txt", "w", stdout);

    int n, k, c, total;
    cin >> n >> k;

    total = 0;
    
    int diffs[n] = {0};

    for (int i = 0; i < n-1; i++) {
        cin >> c;
        total += c;
        diffs[i+1] = k * (i + 1) - total;
    }

    sort(diffs, diffs+n);

    int middle = 0 - diffs[(n-1)/2];
    total = 0;

    for (int i = 0; i < n; i++) {
        diffs[i] = diffs[i] + middle;
        if (diffs[i] > 0) {
            total += diffs[i];
        }
        else {
            total -= diffs[i];
        }
    }

    cout << total;
    return 0;
}
