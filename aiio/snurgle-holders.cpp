#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("snurgle.in", "r", stdin);
    freopen("snurgle.out", "w", stdout);
 
    int n;
    cin >> n;
    int a;
 
    map <int, vector <int>> steps;
    int dp[n+1][2];
 
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        steps[a].push_back(i+1);
    }
 
    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
 
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for (int x: steps[i]) {
            dp[i][0] += max(dp[x][0], dp[x][1]);
            dp[i][1] += dp[x][0];
        }
    }
 
    cout << max(dp[n][0], dp[n][1]);
 
    return 0;
}
