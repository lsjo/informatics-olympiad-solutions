#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    int flowers[n];
    bool issticky[n+3];
    int ends[n+3];

    for (int i = 0; i < n+3; i++) {
        issticky[i] = false;
    }

    vector <pair <int, int>> restrictions;
    vector <pair <int, int>> restricsfinal;

    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        restrictions.push_back({b, a});
    }

    sort(restrictions.begin(), restrictions.end());
    set <int> seen;

    for (int i = m-1; i >= 0; i--) {
        if (! seen.count(restrictions[i].second)) {
            restricsfinal.push_back(restrictions[i]);
            seen.insert(restricsfinal.back().second);
            issticky[restricsfinal.back().second] = true;
        }
    }

    seen.clear();
    
    reverse(restricsfinal.begin(), restricsfinal.end());

    vector <int> dp;
    int maxx = 0;
    int ind = 0;

    dp.push_back(0);

    for (int i = 0; i < n; i++) {
        if (seen.empty()) {
            dp.push_back(dp.back() + flowers[i]);
        }

        else {
            dp.push_back(max(dp.back(), dp[*seen.begin()-1]+flowers[i]));
        }

        if (issticky[i+1]) {
            seen.insert(i+1);
        }

        maxx = max(maxx, dp.back());

        while (restricsfinal[ind].first == i+1) {
            seen.erase(restricsfinal[ind].second);
            ind ++;
        }
    }

    cout << maxx;

    return 0;
}
