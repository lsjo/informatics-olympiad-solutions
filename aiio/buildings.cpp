#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    unordered_set <int> seen;
    int n, k, x; cin >> n >> k >> x;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
 
    bool pos = false;
 
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            seen.insert(heights[i-k]);
        }
        if (seen.count(heights[i]+x) || seen.count(heights[i]-x)) {
            pos = true;
        }
    }
 
    if (pos) cout << "YES";
    else cout << "NO";
    return 0;
}
