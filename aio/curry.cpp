#include <iostream>
#include <cstdio>

bool check(int a, int b, int c) {
    if (a >= 1 and b >= 1) {
        if (a >= c and b >= c) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("curryin.txt", "r", stdin);
    freopen("curryout.txt", "w", stdout);

    int a, b, c;
    int x = 0;
    int y = 0;
    int z = 0;

    std::cin >> a >> b >> c;

    while (check(a, b, c) or check(c, b, a) or check(a, c, b)) {
        if (check(a, b, c)) {
            z ++; a --; b --;
        }

        if (check(c, b, a)) {
            x ++; c--; b--;
        }

        if (check(a, c, b)) {
            y ++; a--; c--;
        }
    }

    std::cout << x << " " << y << " " << z;
    
    return 0;
}
