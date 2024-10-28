#include <iostream>
#include <cstdio>
#include <algorithm>

int main() {
    int n, k;
    int startzero = 0; int startone = 0;

     freopen("distin.txt", "r", stdin);
     freopen("distout.txt", "w", stdout);

    std::cin >> n >> k;

    int locs[n];
    int last;

    for (int i = 0; i < n; i++) {
        std::cin >> locs[i];
    }

    std::sort(locs, locs+n);

    for (int i=0; i < n; i++) {
        if (i == 0) {
            startzero ++;
            last = locs[i];
        }

        else {
            if (locs[i] - last >= k) {
                startzero ++;
                last = locs[i];
            }
        }
    }

    std::cout << std::max(startzero, startone);

    return 0;
}
