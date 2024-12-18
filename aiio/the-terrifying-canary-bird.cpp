#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
    freopen("birdin.txt", "r", stdin);
    freopen("birdout.txt", "w", stdout);
    
    int r, c;
    cin >> r >> c;
 
    int grid[r][c];
    long long paths[r][c];
    int sources[r][c];
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            paths[i][j] = 0;
            sources[i][j] = 0;
        }
    }
 
    queue <pair <int, int>> nums;
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i > 0) {
                if (grid[i-1][j] > grid[i][j]) {
                    sources[i][j] ++;
                }
            }
            if (j > 0) {
                if (grid[i][j-1] > grid[i][j]) {
                    sources[i][j] ++;
                }
            }
            if (i < r-1) {
                if (grid[i+1][j] > grid[i][j]) {
                    sources[i][j] ++;
                }
            }
            if (j < c-1) {
                if (grid[i][j+1] > grid[i][j]) {
                    sources[i][j] ++;
                }
            }
 
            if (sources[i][j] == 0) {
                paths[i][j] = 1;
                nums.push({i, j});
            }
        }
    }
 
    while (! nums.empty()) {
        pair <int, int> pos = nums.front();
        paths[pos.first][pos.second] = paths[pos.first][pos.second] % 1000003;
        nums.pop();
        if (pos.first > 0) {
            if (grid[pos.first-1][pos.second] < grid[pos.first][pos.second]) {
                paths[pos.first-1][pos.second] += paths[pos.first][pos.second];
                sources[pos.first-1][pos.second] --;
                if (sources[pos.first-1][pos.second] == 0) {
                    nums.push({pos.first-1, pos.second});
                }
            }
        }
        if (pos.first < r-1) {
            if (grid[pos.first+1][pos.second] < grid[pos.first][pos.second]) {
                paths[pos.first+1][pos.second] += paths[pos.first][pos.second];
                sources[pos.first+1][pos.second] --;
                if (sources[pos.first+1][pos.second] == 0) {
                    nums.push({pos.first+1, pos.second});
                }
            }
        }
        if (pos.second > 0) {
            if (grid[pos.first][pos.second-1] < grid[pos.first][pos.second]) {
                paths[pos.first][pos.second-1] += paths[pos.first][pos.second];
                sources[pos.first][pos.second-1] --;
                if (sources[pos.first][pos.second-1] == 0) {
                    nums.push({pos.first, pos.second-1});
                }
            }
        }
        if (pos.second < c-1) {
            if (grid[pos.first][pos.second+1] < grid[pos.first][pos.second]) {
                paths[pos.first][pos.second+1] += paths[pos.first][pos.second];
                sources[pos.first][pos.second+1] --;
                if (sources[pos.first][pos.second+1] == 0) {
                    nums.push({pos.first, pos.second+1});
                }
            }
        }
    }
 
    long long totalpaths = 0;
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bool smallest = true;
            if (i > 0 && grid[i][j] > grid[i-1][j]) {
                smallest = false;
            }
            else if (i < r-1 && grid[i][j] > grid[i+1][j]) {
                smallest = false;
            }
            else if (j > 0 && grid[i][j] > grid[i][j-1]) {
                smallest = false;
            }
            else if (j < c-1 && grid[i][j] > grid[i][j+1]) {
                smallest = false;
            }
 
            if (smallest) {
                totalpaths += paths[i][j];
                totalpaths = totalpaths % 1000003;
            }
        }
    }
 
    cout << totalpaths << "\n";
 
 
    return 0;
}
