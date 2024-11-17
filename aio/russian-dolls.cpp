#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("dollin.txt", "r", stdin);
    freopen("dollout.txt", "w", stdout);

    int n, num, a;
    cin >> n;
    vector <int> assigned;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (upper_bound(assigned.begin(), assigned.end(), num) == assigned.end()) {
            assigned.push_back(num);
        }
        else {
            a = upper_bound(assigned.begin(), assigned.end(), num) - assigned.begin();
            assigned[a] = num;
        }
    }

    cout << assigned.size();

    return 0;
}
