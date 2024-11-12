#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("atlanin.txt", "r", stdin);
    freopen("atlanout.txt", "w", stdout);
 
    int r, c;
    cin >> r >> c;
    int a, b;
    int currentr;
    int currentc;
    int maximum;
    cin >> a >> b;
    a--; b--;
    vector <int> rvisit;
    vector <int> cvisit;
 
    int heights[r][c];
    int maxvis[r][c];
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> heights[i][j];
            maxvis[i][j] = 0;
        }
    }
 
    rvisit.push_back(a); cvisit.push_back(b);
    maximum = 1;
    maxvis[a][b] = 1;
 
    while (! rvisit.empty()) {
        currentr = rvisit.back();
        currentc = cvisit.back();
        rvisit.pop_back(); cvisit.pop_back();
        if (currentr > 0) {
            if (heights[currentr-1][currentc] < heights[currentr][currentc] && maxvis[currentr-1][currentc] < maxvis[currentr][currentc]+1) {
                maxvis[currentr-1][currentc] = maxvis[currentr][currentc] + 1;
                rvisit.push_back(currentr-1);
                cvisit.push_back(currentc);
            }
        }
        if (currentr < r-1) {
            if (heights[currentr+1][currentc] < heights[currentr][currentc] && maxvis[currentr+1][currentc] < maxvis[currentr][currentc]+1) {
                maxvis[currentr+1][currentc] = maxvis[currentr][currentc] + 1;
                rvisit.push_back(currentr+1);
                cvisit.push_back(currentc);
            }
        }
 
        if (currentc < c-1) {
            if (heights[currentr][currentc+1] < heights[currentr][currentc] && maxvis[currentr][currentc+1] < maxvis[currentr][currentc]+1) {
                maxvis[currentr][currentc+1] = maxvis[currentr][currentc] + 1;
                rvisit.push_back(currentr);
                cvisit.push_back(currentc+1);
            }
        }
 
        if (currentc > 0) {
            if (heights[currentr][currentc-1] < heights[currentr][currentc] && maxvis[currentr][currentc-1] < maxvis[currentr][currentc]+1) {
                maxvis[currentr][currentc-1] = maxvis[currentr][currentc] + 1;
                rvisit.push_back(currentr);
                cvisit.push_back(currentc-1);
            }
        }
 
        maximum = max(maximum, maxvis[currentr][currentc]);
    }
 
    cout << maximum;
    return 0;
}
