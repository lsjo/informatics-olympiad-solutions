#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector <int> f, q;

    f.push_back(1);
    q.push_back(1); q.push_back(1);

    for (int i = 1; i <= n; i++) {
        int backf;
        if (i >= 2) backf = f[i - 2];
        else backf = 0;

        int num = ((((backf*q[i-1]*backf)%m) + ((f[i-1]*f[i-1]) % m) + 1)) % m;
        f.push_back(num);

        if (f.size() > q.size()) {
            num = ((backf*q[i-1]*backf) % m + 1) % m;
            q.push_back(num);
        }

    }

    cout << f.back() % m;
    return 0;
}
