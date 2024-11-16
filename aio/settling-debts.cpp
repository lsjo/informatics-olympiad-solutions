#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("debtsin.txt", "r", stdin);
    freopen("debtsout.txt", "w", stdout);

    int n;
    cin >> n;
    int num;
    int total = 0;
    int last = 0;
    int movenum = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;
        total += num;
        if (total > last) {
            last = total;
            movenum = (i+1) % n;
        }
    }

    cout << movenum + 1;
    return 0;
}
