#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("spiesin.txt", "r", stdin);
    freopen("spiesout.txt", "w", stdout);

    int n, a, b;
    cin >> n;

    vector <int> x;
    vector <int> y;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[x.size() / 2] << " " << y[y.size() / 2];
    return 0;
}
