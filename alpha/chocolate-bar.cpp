#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
    int n, a, r, l;
    int diff = 100000000;
    cin >> n;
 
    int nums[n];
    int prefix = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> a;
        prefix += a;
        nums[i] = prefix;
    }
 
    int last = nums[n-1];
 
    for (int i = 0; i < n-1; i++) {
        r = last - nums[i];
        l = nums[i];
        diff = min(diff, abs(r-l));
    }
 
    cout << diff;
    return 0;
}
