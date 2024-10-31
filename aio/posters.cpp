#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    freopen("postin.txt", "r", stdin);
    freopen("postout.txt", "w", stdout);

    int n;
    cin >> n;
    int start;
    int width;
    int num;
    int last = -1;

    vector <int> wallstarts;

    for (int i = 0; i < 1010011; i++) {
        wallstarts.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        cin >> start >> width;
        wallstarts.at(start) = i + 1;
        wallstarts.at(start+width-1) = i + 1;
    }

    for (int i = 0; i < 1010010; i++) {
        num = wallstarts.at(i);
        if (num != 0) {
            if (num > last) {
                last = num;
            }

            else if (num == last) {
                break;
            }
        }

    }

    cout << last;
    
    return 0;
}
