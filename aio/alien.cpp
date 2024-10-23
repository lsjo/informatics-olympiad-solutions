#include <iostream>
#include <cstdio>

int main() {
    int n;
    int w;

    freopen("alienin.txt", "r", stdin);
    freopen("alienout.txt", "w", stdout);

    std::cin >> n;
    std::cin >> w;

    int pos[n];

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        pos[i] = num;
    }

    int i = 0;
    int j = 0;
    int total = 0;

    while (true) {
        if (pos[j] - pos[i] < w) {
            total = std::max(total, j-i+1);
            j ++;
            if (j == n) {
                break;
            }
        }

        else {
            i ++;
        }
    }

    std::cout << total;
    return 0;
}
