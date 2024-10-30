#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("tennisin.txt", "r", stdin);
    freopen("tennisout.txt", "w", stdout);

    int n, m;
    int a, b;
    cin >> n >> m;
    long long starts[n];
    long long round1[n];
    long long maxdecrease[n];
    long long change[n];
    long long instrucsa[m];
    long long instrucsb[m];
    long long instrucs = 0;
    bool broken = false;
    bool zeroes = false;
    long long num;

    for (int i = 0; i < n; i++) {
        cin >> starts[i];
        round1[i] = starts[i];
        maxdecrease[i] = 0;
        change[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        change[a-1]--;
        change[b-1]++;
        maxdecrease[a-1] = min(change[a-1], maxdecrease[a-1]);
        instrucsa[i] = a-1;
        instrucsb[i] = b-1;
        round1[a-1] --;
        round1[b-1] ++;

        if (round1[a-1] == -1) {
            broken = true;
            std::cout << instrucs;
            break;
        }

        instrucs ++;
    }

    instrucs = 0;

    if (!broken) {
        for (int i = 0; i < n; i++) {
            if (change[i] != 0) {
                zeroes = true;
                break;
            }
        }

        if (! zeroes) {
            std::cout << "FOREVER";
            broken = true;
        }

        if (! broken) {

            long long lowround = 100000000000000000;
            for (int i=0; i<n; i++) {
                if (change[i] < 0) {
                    num = (starts[i]+maxdecrease[i]) / (0-change[i]) + 2;
                    lowround = min(lowround, num);
                }
            }

            instrucs += m * (lowround-1);

            for (int i = 0; i < n; i++) {
                starts[i] += change[i] * (lowround-1);
            }

            for (int i = 0; i < m; i++) {
                starts[instrucsa[i]] --;
                starts[instrucsb[i]] ++;

                if (starts[instrucsa[i]] < 0) {
                    broken = true;
                    std::cout << instrucs;
                    break;
                }

                instrucs++;
            }

        }

    }


    return 0;
}
