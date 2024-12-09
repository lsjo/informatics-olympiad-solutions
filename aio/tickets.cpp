#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("ticketin.txt", "r", stdin);
    freopen("ticketout.txt", "w", stdout);
 
    int costa, daysa, costb, daysb;
 
    cin >> costa >> daysa >> costb >> daysb;
 
    int n;
    cin >> n;
 
    vector <int> dp(n+1, 10000000);
    vector <int> days(n+1, -10000000);
 
    dp[0] = 0;
 
    for (int i = 1; i <= n; i++) {
        cin >> days[i];
    }
 
    for (int i = 1; i <= n; i++) {
        int j = i-1;
        while (days[i]-days[j]+1 <= daysa) {j--;}
        dp[i] = min(dp[i], dp[j]+costa);
        
        j = i-1;
        while (days[i]-days[j]+1 <= daysb) {j--;}
        dp[i] = min(dp[i], dp[j]+costb);
    }
 
    cout << dp[n];
 
    return 0;
}
