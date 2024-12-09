#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int w, h, a;
    cin >> w >> h;
 
    int cuts = 0;
 
    vector <int> top;
    vector <int> bottom;
 
    for (int i = 0; i < w; i++) {
        cin >> a;
        cuts += 2;
 
        if (top.empty()) {
            top.push_back(a);
            if (a==h) {
                cuts -= 1;
            }
        }
        else {
            if (a == top.back()) {
                cuts -= 2;
            }
            else {
                while (! top.empty() && a > top.back()) {
                    top.pop_back();
                }
 
                if (! top.empty() && a == top.back()) {
                    cuts -= 1;
                }
 
                else {
                    top.push_back(a);
                    if (a == h) {
                        cuts -= 1;
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < w; i++) {
        cin >> a;
        cuts += 2;
        if (bottom.empty()) {
            bottom.push_back(a);
            if (a==0) {
                cuts -= 1;
            }
        }
        else {
            if (a == bottom.back()) {
                cuts -= 2;
            }
            else {
                while (! bottom.empty() && a < bottom.back()) {
                    bottom.pop_back();
                }
                if (! bottom.empty() && a == bottom.back()) {
                    cuts -= 1;
                }
                else {
                    bottom.push_back(a);
                    if (a==0) {
                        cuts -= 1;
                    }
                }
            }
        }
    }
 
    cuts -= 2;
    cout << cuts;
    return 0;
}
