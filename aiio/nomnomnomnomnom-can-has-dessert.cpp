#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("nomin.txt", "r", stdin);
    freopen("nomout.txt", "w", stdout);
 
    int n;
    cin >> n;
    long long total, maxtotal = 0, prefix[n];
 
    int nums[n];
 
    long long running = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        running += nums[i];
        prefix[i] = running;
    }
    
    int j = 0;
 
    for (int i = 0; i < n; i++) {
        bool broken = false;
        while (prefix[j] < 2*prefix[i]) {
            j ++;
            if (j == n) {
                j--;
                broken = true;
                break;
            }
        }

        if (broken) break;
        if (prefix[i]*2 == prefix[j]) maxtotal = max(maxtotal, prefix[i]);
    }
 
    cout << maxtotal << "\n";
 
    return 0;
}
