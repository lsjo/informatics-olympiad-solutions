#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen("chimin.txt", "r", stdin);
    freopen("chimout.txt", "w", stdout);

    int n;
    string a;
    string b;
    string splice;
    int splicesa = 0;
    int splicesb = 0;

    cin >> n >> a >> b >> splice;

    int current = 0;

    for (int i=0; i < n; i++) {
        if (current == 0) {
            if (a[i] != splice[i]) {
                if (b[i] != splice[i]) {
                    splicesa = -1;
                    break;
                }
                
                else {
                    splicesa ++;
                    current = 1;
                }
            }
        }

        else {
            if (b[i] != splice[i]) {
                if (a[i] != splice[i]) {
                    splicesa = -1;
                    break;
                }

                else {
                    splicesa ++;
                    current = 0;
                }
            }
        }
    }

    current = 1;

    for (int i=0; i < n; i++) {
        if (current == 0) {
            if (a[i] != splice[i]) {
                if (b[i] != splice[i]) {
                    splicesb = -1;
                    break;
                }
                
                else {
                    splicesb ++;
                    current = 1;
                }
            }
        }

        else {
            if (b[i] != splice[i]) {
                if (a[i] != splice[i]) {
                    splicesb = -1;
                    break;
                }

                else {
                    splicesb ++;
                    current = 0;
                }
            }
        }
    }

    if (splicesa == -1) {
        cout << "PLAN FOILED";
    }

    else {
        cout << "SUCCESS\n" << min(splicesa, splicesb);
    }

    return 0;

}
