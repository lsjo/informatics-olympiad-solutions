#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("slicein.txt", "r", stdin);
    freopen("sliceout.txt", "w", stdout);

    int n, num;
    cin >> n;

    int times[n];
    int covered[n];

    int total = 1;
    int maxval = 1;

    for (int i = 0; i < n; i++) {
        cin >>  num;
        times[num-1] = i;
        covered[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        num = times[i];
        if (num == 0) {
            if (covered[1] == 1) {
                total --;
            }
        }

        else if (num == n-1) {
            if (covered[n-2] == 1) {
                total--;
            }
        }

        else {
            if (covered[num+1] == 1 && covered[num-1] == 1) {
                total --;
            }

            else if (covered[num+1] == 0 && covered[num-1] == 0) {
                total ++;
            }
        }

        covered[num] = 1;

        maxval = max(maxval, total);
    }

    cout << maxval;
    return 0;
}
