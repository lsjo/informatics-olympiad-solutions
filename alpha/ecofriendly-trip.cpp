#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    int nums[n][n];
    int prefix[n][n];
    int dp[n][n];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
            prefix[i][j] = 0;
            dp[i][j] = 1000000000;
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i-1][j-1];
            }
            if (i > 0) {
                prefix[i][j] += prefix[i-1][j];
            }
            if (j > 0) {
                prefix[i][j] += prefix[i][j-1];
            }
            prefix[i][j] += nums[i][j];
        }
    }
 
    dp[0][0] = prefix[k/2][k/2];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                if (i+k/2 > n-1) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                }
 
                else {
                    int right = min(n-1, j+(k/2));
                    int left = max(-1, j-(k/2)-1);
                    if (left == -1) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j]+prefix[i+k/2][right]-prefix[i+k/2-1][right]);
                    }
                    else {
                        dp[i][j] = min(dp[i][j], dp[i-1][j]+prefix[i+k/2][right]-prefix[i+k/2-1][right]-prefix[i+k/2][left]+prefix[i+k/2-1][left]);
                    }
 
                }
 
            }
            
            if (j > 0) {
                if (j+k/2 > n-1) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
 
                else {
                    int bottom = min(n-1, i+(k/2));
                    int top = max(-1, i-(k/2)-1);
 
                    if (top == -1) {
                        dp[i][j] = min(dp[i][j], dp[i][j-1]+prefix[bottom][j+k/2]-prefix[bottom][j+k/2-1]);
                    }
                    else {
                        dp[i][j] = min(dp[i][j], dp[i][j-1]+prefix[bottom][j+k/2]-prefix[bottom][j+k/2-1]-prefix[top][j+k/2]+prefix[top][j+k/2-1]);
                    }
                }
            }
 
        }
    }
 
    cout << dp[n-1][n-1];
 
 
    return 0;
}
