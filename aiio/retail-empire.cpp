#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
    int n, a, k; cin >> n >> a >> k;
    int costs[n+1], profits[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> costs[i] >> profits[i];
    }
 
    int dp[n+1][k+5];
    for (int i = 0; i <= n; i++) {dp[i][0] = 0;}
    for (int i = 0; i <= k+1; i++) {dp[0][i] = 0;}
 
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i-1][j];
            if (j >= costs[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-costs[i]]+profits[i]);
            }
        }
    }
 
    int daily = a;
    int count = 1;
 
    while (daily < k) {
        count += 1;
        int maxprof = dp[n][daily];
        daily += maxprof;
    }
 
    cout << count;
    return 0;
}
