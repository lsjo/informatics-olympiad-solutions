#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, k;

    freopen("backin.txt", "r", stdin);
    freopen("backout.txt", "w", stdout);

    cin >> n >> k;

    int dists[n-1];
    int distspre[n] = {0};
    int costs[n];
    int cheaps[20];
    int mins[n] = {0};
    int cans = 0;
    int totalcost = 0;
    int a;
    int minam;
    int minj;

    for (int i = 0; i < n-1; i++) {
        cin >> dists[i];
        distspre[i+1] = distspre[i] + dists[i];
        mins[i+1] = 0;
    }

    for (int i = 0; i < 20; i++) {
        cheaps[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    for (int i = n-1; i >= 0; i--) {
        
        a = costs[i] - 1;
        cheaps[a] = i;
        minam = 2000000000;

        for (int j = a-1; j >= 0; j--) {
            if (cheaps[j] == -1) {
                continue;
            }

            minam = min(minam, cheaps[j]);
        }

        if (minam == 2000000000) {
            mins[i] = i;
        }

        else {
            mins[i] = minam;
        }
    }

    int num;

    for (int i = 0; i < n-1; i++) {
        minj = mins[i];
        if (distspre[minj] - distspre[i] > k) {
            minj = i;
        }

        if (minj == i) {
            num = min(k-cans, distspre[n-1]-distspre[i]-cans);
            cans += num;
            totalcost += num * costs[i];
        }

        else {
            num = min(distspre[minj] - distspre[i] - cans, distspre[n-1]-distspre[i]-cans);
            num = max(0, num);
            cans += num;
            totalcost += num * costs[i];
        }

        cans -= distspre[i+1] - distspre[i];
    }

    cout << totalcost;
}
