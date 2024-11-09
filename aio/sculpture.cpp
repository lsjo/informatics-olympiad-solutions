#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    freopen("sculpin.txt", "r", stdin);
    freopen("sculpout.txt", "w", stdout);

    int n;
    int a, x, b, y, num;
    deque <int> to_visit;
    cin >> n;
    int apples[n][4];
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> x >> b >> y;
        if (i == 0) {
            for (int k = 0; k < 4; k++) {
                apples[i][k] = 0;
            }
        }

        if (a + x + b + y != 0) {
            apples[a-1][0] = 0;
            apples[a-1][1] = 0;
            apples[a-1][2] = i;
            apples[a-1][3] = x;

            apples[b-1][0] = 0;
            apples[b-1][1] = 0;
            apples[b-1][2] = i;
            apples[b-1][3] = y;
        }

        else {
            apples[i][0] = 0;
            apples[i][1] = 0;
            to_visit.push_back(i);
        }
        
    }

    while (! to_visit.empty()) {
        num = to_visit.front();
        to_visit.pop_front();
        if (apples[apples[num][2]][0] != 0) {
            apples[apples[num][2]][1] = apples[num][3];
            total += abs(apples[apples[num][2]][1]-apples[apples[num][2]][0]);
            apples[apples[num][2]][1] = max(apples[apples[num][2]][1], apples[apples[num][2]][0]);
            apples[apples[num][2]][0] = apples[apples[num][2]][1];
            apples[apples[num][2]][3] = apples[apples[num][2]][3] + apples[apples[num][2]][0];
            to_visit.push_back(apples[num][2]);
        }

        else {
            apples[apples[num][2]][0] = apples[num][3];
        }

        if (to_visit.front() == num) {
            break;
        }
    }

    cout << total;
    return 0;
}
