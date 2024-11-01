#include <iostream>
#include <vector>
#include <cstdio>
#include <tuple>

using namespace std;

int main() {
    int n, k;
    int num;
    vector <tuple <int, int>> cabinet;
    vector <int> ministack;
    int assigned = 0;
    int a = 0;
    int b = 0;
    int x = 0;
    int pm = 0;

    freopen("shufflein.txt", "r", stdin);
    freopen("shuffleout.txt", "w", stdout);

    cin >> n >> k;

    int chairpos[k];
    int minipos[k+1];

    for (int i = 0; i < k; i++) {
        cin >> num;
        chairpos[i] = num;
    }

    for (int i = 0; i < k+1; i++) {
        cin >> num;
        minipos[i] = num;
    }

    while (a < k+1 && b < k) {
        if (minipos[a] <= chairpos[b]) {
            cabinet.push_back({a+1, 0});
            a++;
        }

        else {
            cabinet.push_back({b+1, 1});
            b++;
        }
    }

    while (a < k+1) {
        cabinet.push_back({a+1, 0});
        a++;
    }

    while (b < k) {
        cabinet.push_back({b+1, 1});
        b++;
        }

    while (assigned != k) {
        if (get<1>(cabinet[x]) == 1) {
            if (ministack.empty()) {
                cabinet.push_back(cabinet[x]);
            }

            else {
                if (get<0>(cabinet[x]) == 1) {
                    pm = ministack.back();
                }
                ministack.pop_back();
                assigned ++;
            }
        }

        else {
            ministack.push_back(get<0>(cabinet[x]));
        }

        for (int i = 0; i < ministack.size(); i++) {
        }

        x ++;
    }

    if (ministack.empty()) {
        std::cout << pm << "\n" << k+1;
    }

    else {
        std::cout << pm << "\n" << ministack.back();
    }

}
