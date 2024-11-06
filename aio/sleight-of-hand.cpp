#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("handin.txt", "r", stdin);
    freopen("handout.txt", "w", stdout);

    int a, b, c, start, end;
    cin >> a >> b >> c;

    for (int i = 0; i < c; i++) {
        cin >> start >> end;
        if (b == start) {
            b = end;
        }

        else if (start < b && end >= b) {
            b --;
        }

        else if ((start > b && end <= b)) {
            b ++;
        }
    }

    cout << b;
    return 0;
}
