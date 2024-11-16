#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("surfin.txt", "r", stdin);
    freopen("surfout.txt", "w", stdout);
 
    int x, y, a, b;
    cin >> x >> y;
    char nums[x][y];
    int visited[x][y];
    int dropped = 0;
    vector <int> explorex;
    vector <int> explorey;
 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> nums[i][j];
            visited[i][j] = 0;
            if (nums[i][j] == '*') {
                dropped ++;
                explorex.push_back(i);
                explorey.push_back(j);
                visited[i][j] = 1;
            }
        }
    }
 
    while (! explorex.empty()) {
        a = explorex.back();
        b = explorey.back();
        explorex.pop_back(); explorey.pop_back();
        if (a > 0) {
            if (nums[a-1][b] == 'v' && visited[a-1][b] == 0) {
                visited[a-1][b] = 1;
                dropped ++;
                explorex.push_back(a-1);
                explorey.push_back(b);
            }
        }
 
        if (b > 0) {
            if (nums[a][b-1] == '>' && visited[a][b-1] == 0) {
                visited[a][b-1] = 1;
                dropped++;
                explorex.push_back(a);
                explorey.push_back(b-1);
            }
        }
    }
 
    cout << dropped;
    return 0;
}
