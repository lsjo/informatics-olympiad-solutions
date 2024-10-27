#include <iostream>
#include <cstdio>

int main() {
    int n;
    int count = 0;

    freopen("atlanin.txt", "r", stdin);
    freopen("atlanout.txt", "w", stdout);

    std::cin >> n;

    int maxleft[n];
    int maxright[n];
    int heights[n];

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        heights[i] = num;

        if (i == 0) {
            maxleft[0] = num;
        }

        else {
            maxleft[i] = std::max(maxleft[i-1], num);
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) {
            maxright[i] = heights[i];
        }

        else {
            maxright[i] = std::max(maxright[i+1], heights[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (heights[i] < maxleft[i] and heights[i] < maxright[i]) {
            count ++;
        }

    }

    std::cout << count;

}
