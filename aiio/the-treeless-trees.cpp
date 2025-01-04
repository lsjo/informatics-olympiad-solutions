#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int nums[n];
    int cuts[n];
 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cuts[i] = 1000000000;
    }
 
    vector <int> stack;
    stack.push_back(0);
 
    for (int i = 0; i < n; i++) {
        while (! stack.empty() && nums[i] < stack.back()) {
            stack.pop_back();
        }
 
        cuts[i] = min(cuts[i], nums[i]-stack.back());
        stack.push_back(nums[i]);
    }
 
    stack.clear();
    stack.push_back(0);
 
    for (int i = n-1; i >= 0; i--) {
        while (! stack.empty() && nums[i] <= stack.back()) {
            stack.pop_back();
        }
        cuts[i] = min(cuts[i], nums[i]-stack.back());
        stack.push_back(nums[i]);
    }
 
    long long total = 0;
 
    for (int i = 0; i < n; i++) {
        total += cuts[i];
    }
 
    cout << total;
    return 0;
}
