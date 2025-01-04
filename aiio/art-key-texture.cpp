#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
signed main() {
    int h, w; cin >> h >> w;
    int beauty[h][w], fromleft[h][w], fromright[h][w];
 
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {cin >> beauty[i][j];}
    }
 
    for (int j = 0; j < w; j++) {
        long long prefix = 0;
        long long maxtot = 0;
        for (int i = h-1; i >= 0; i--) {
            prefix += beauty[i][j];
            maxtot = max(maxtot, prefix);
            if (j > 0) {
                fromleft[i][j] = prefix + fromleft[i][j-1];
                fromleft[i][j] = max(fromleft[i][j], maxtot);
                maxtot = max(maxtot, fromleft[i][j]);
            }
            else {
                fromleft[i][j] = maxtot;
            }
        }
    }
 
    for (int j = w-1; j >= 0; j--) {
        long long prefix = 0;
        long long maxtot = 0;
        for (int i = h-1; i >= 0; i--) {
            prefix += beauty[i][j];
            maxtot = max(maxtot, prefix);
            if (j < w-1) {
                fromright[i][j] = prefix + fromright[i][j+1];
                fromright[i][j] = max(fromright[i][j], maxtot);
                maxtot = max(maxtot, fromright[i][j]);
            }
            else {
                fromright[i][j] = maxtot;
            }
        }
    }
 
    int total = 0;
 
    for (int i = 0; i < w-1; i++) {
        total = max(total, fromleft[0][i]+fromright[0][i+1]);
    }
 
    if (w == 1) total = fromleft[0][0];
 
    cout << total;
 
    return 0;
}
