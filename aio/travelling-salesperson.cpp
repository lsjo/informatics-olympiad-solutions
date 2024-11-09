#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("salesin.txt", "r", stdin);
    freopen("salesout.txt", "w", stdout);
    
    int a, b, c;
    cin >> a >> b >> c;

    cout << max(a+b, max(a+c, b+c));
    return 0;
}
