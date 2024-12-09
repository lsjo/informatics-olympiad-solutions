#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
    int w, h;
    int a, b;
    cin >> w >> h;
    int maxnum = 0;
 
    int arr[h][w];
    queue <pair <int, int>> to_visit;
 
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
            arr[i][j] = arr[i][j] - 1;
            if (arr[i][j] == 0) {
                to_visit.push({i, j});
            }
        }
    }
 
    while (! to_visit.empty()) {
        a = to_visit.front().first;
        b = to_visit.front().second;
 
        maxnum = max(maxnum, arr[a][b]);
 
        to_visit.pop();
 
        if (a > 0 && arr[a-1][b] == -1) {
            arr[a-1][b] = arr[a][b] + 1;
            to_visit.push({a-1, b});
        }   
 
        if (a < h-1 && arr[a+1][b] == -1) {
            arr[a+1][b] = arr[a][b] + 1;
            to_visit.push({a+1, b});
        } 
 
        if (b > 0 && arr[a][b-1] == -1) {
            arr[a][b-1] = arr[a][b] + 1;
            to_visit.push({a, b-1});
        }
 
        if (b < w-1 && arr[a][b+1] == -1) {
            arr[a][b+1] = arr[a][b] + 1;
            to_visit.push({a, b+1});
        }
    }
 
    cout << maxnum;
    return 0;
}
