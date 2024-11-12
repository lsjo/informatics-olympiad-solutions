#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
    freopen("chocin.txt", "r", stdin);
    freopen("chocout.txt", "w", stdout);
 
    int n, num;
    int total = 0;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> num;
        total += num;
        total = total % 10;
    }
 
    if (total == 0) {
        cout << 0;
    }
 
    else {
        cout << 10 - total;
    }
    return 0;
}
