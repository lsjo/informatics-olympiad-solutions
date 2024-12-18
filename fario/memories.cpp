#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, r, c;
    cin >> n >> r >> c;
 
    vector <int> nums;
 
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }
 
    sort(nums.begin(), nums.end());
 
    int lo = 0;
    int hi = 1000000005;
 
    while (lo != hi) {
        int mid = (lo + hi) / 2;
 
        int count = 0;
        int currdiff = 0;
 
        for (int i = c-1; i < n; i++) {
            if (nums[i]-nums[i-c+1] <= mid) {
                count ++;
                i += c -1;
            }
        }
 
        if (count >= r) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
 
    cout << lo;
 
    return 0;
}
