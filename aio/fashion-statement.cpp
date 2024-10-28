#include <iostream>
#include <cstdio>

int main() {
    int num;
    freopen("fashin.txt", "r", stdin);
    freopen("fashout.txt", "w", stdout);

    std::cin >> num;

    int count = 0;

    while (num >= 100) {
        count ++;
        num = num - 100;
    }

    while (num >= 20) {
        count ++;
        num = num - 20;
    }

    while (num >= 5) {
        count ++;
        num = num - 5;
    }

    while (num >= 1) {
        count ++;
        num = num - 1;
    }

    std::cout << count;

    return 0;
}
