#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
    int n; cin >> n;
    int personalities[n];
    set <pair <int, int>> students;
    for (int i = 0; i < n; i++) {
        cin >> personalities[i];
        students.insert({personalities[i], i});
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int s; cin >> s;
            s--;
            int ps = personalities[s];
            pair <int, int> minp = *students.begin();
            pair <int, int> maxp = *students.rbegin();
            if (abs(maxp.first-ps) > abs(minp.first-ps)) {
                if (maxp.second > s) cout << n << "\n";
                else cout << 1 << "\n";
            }
            else if (abs(maxp.first-ps) < abs(minp.first-ps)) {
                if (minp.second > s) cout << n << "\n";
                else cout << 1 << "\n";
            }
            else {
                if (minp.second < s && maxp.second < s) cout << 1 << "\n";
                else if (minp.second > s && maxp.second > s) cout << n << "\n";
                else cout << -1 << "\n";
            }
        }
 
        else {
            int s, x; cin >> s >> x;
            students.erase({personalities[s-1], s-1});
            students.insert({x, s-1});
            personalities[s-1] = x;
        }
    }
    return 0;
}
