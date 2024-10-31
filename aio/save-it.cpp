#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    map <int, int> rems = {{2, 0}, {3, 0}, {4, 0}};
    freopen("savein.txt", "r", stdin);
    freopen("saveout.txt", "w", stdout);

    int n, num, bigdiv, total, x;
    cin >> n;

    total = 0;

    for (int i=0; i < n; i++) {
        cin >> num;
        if (num % 5 != 0 and num % 5 != 1) {
            rems[num % 5] ++;
        }

        bigdiv = num / 5;
        total += bigdiv * 5;
    }

    num = min(rems[3], rems[4]);
    total += num * 5;
    rems[3] -= num; rems[4] -= num;

    if (rems[3] > 0) {
        total += ((rems[3]+1) / 2) * 5;
    }

    else if (rems[4] > 0) {
        total += 5 * (rems[4] - (rems[4] / 3));
    }

    std::cout << total;

}
