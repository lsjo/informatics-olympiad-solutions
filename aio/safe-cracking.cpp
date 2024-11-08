#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b, lasti, lastj;

    freopen("safein.txt", "r", stdin);
    freopen("safeout.txt", "w", stdout);

    cin >> a >> b;

    bool found = false;

    int code[a];
    int codediffs[a-1];
    int paperdiffs[b-1];
    int poss[b-1];
    int paper[b];

    for (int i = 0; i < a; i++) {
        cin >> code[i];
        if (i > 0) {
             codediffs[i-1] = code[i] - code[i-1];
        }
    }

    for (int i = 0; i < b; i++) {
        cin >> paper[i];
        if (i > 0) {
            paperdiffs[i-1] = paper[i] - paper[i-1];
        }
    }

    for (int i = 0; i < a - b + 2; i++) {
        for (int j = 0; j < b - 1; j++) {
            if (paperdiffs[j] != codediffs[i+j]) {
                break;
            }

            else if (paper[j-1] > code[i+j-1]) {
                break;
            }

            else {
                if (j == b-2) {
                    found = true;
                    lastj = j;
                    lasti = i;
                    break;
                }
            }
        }

        if (found) {break;}
    }

    int difference = paper[0] - code[lasti];

    for (int i = 0; i < a; i++) {
        cout << code[i] + difference;
        if (i+1 < a) {
            cout << "\n";
        }
    }

}
