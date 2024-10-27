#include <iostream>
#include <string>
#include <cstdio>

int main() {
    int length;
    std::string a;
    std::string b;
    std::string c;

    int allcount = 0;
    int excla = 0;
    int exclb = 0;
    int exclc = 0;
    int diffcount = 0;
    int totala = 0;
    int totalb = 0;
    int totalc = 0;

    freopen("chimin.txt", "r", stdin);
    freopen("chimout.txt", "w", stdout);
    
    std::cin >> length;
    std::cin >> a >> b >> c;

    for (int i = 0; i < length; i++) {
        if (a[i] == b[i] and b[i] == c[i]) {
            allcount += 1;
        }

        else if (a[i] == b[i]) {
            exclc ++;
            totala ++;
            totalb ++;
        }

        else if (b[i] == c[i]) {
            excla ++;
            totalb ++;
            totalc ++;
        }

        else if (c[i] == a[i]) {
            exclb ++;
            totala ++;
            totalc ++;
        }

        else {
            diffcount ++;
        }
    }

        while (diffcount != 0) {
        if (totala <= totalb and totala <= totalc) {
            totala ++;
        }

        else if (totalb <= totala and totalb <= totalc) {
            totalb ++;
        }

        else {
            totalc ++;
        }

        diffcount --;
    }

    while (totala < totalb and totala < totalc and excla > 0) {
        totalb --;
        totalc --;
        totala ++;
        excla --;
    }

    while (totalb < totala and totalb < totalc and exclb > 0) {
        totalb ++;
        totalc --;
        totala --;
        exclb --;
    }

    while (totalc < totala and totalc < totalb and exclc > 0) {
        totalb --;
        totalc ++;
        totala --;
        exclc --;
    }

    int num = std::min(std::min(totala, totalb), totalc) + allcount;
    std::cout << num;

    return 0;
}
