#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int x, w; cin >> x >> w;
    int nums[x];
    long long score = 0;
    for (int i = 0; i < x; i++) {
        cin >> nums[i];
        score += nums[i];
    }
    map <int, int> numsdict;
    for (int i = 0; i < w; i++) {
        int num; cin >> num;
        if (numsdict.count(num)) {
            score += numsdict[num];
        }
        else {
            int maxtotal = 0;
            int curr = 0;
            for (int i = 0; i < x; i++) {
                curr += nums[i];
                if (i >= num) {
                    curr -= nums[i-num];
                    maxtotal = max(maxtotal, curr);
                }
                if (i == num-1) maxtotal = max(maxtotal, curr);
            }
            numsdict[num] = maxtotal;
            score += maxtotal;
        }
    }
    cout << score;
    return 0;
}
