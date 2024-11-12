#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
    freopen("psychin.txt", "r", stdin);
    freopen("psychout.txt", "w", stdout);
 
    int cardnum[13];
    int prefix[13];
    int num;
    int lose;
    int ans = 0;
 
    for (int i = 0; i < 13; i++) {
        cin >> num;
        cardnum[num-1] = i+1;
    }
 
    prefix[0] = cardnum[0];
    for (int i = 1; i < 13; i++) {
        prefix[i] = prefix[i-1] + cardnum[i];
    }
 
    for (int i = 1; i < 13; i++) {
        ans = max(ans, prefix[i]-cardnum[i]-cardnum[i]);
    }
 
    cout << ans;
    return 0;
}
