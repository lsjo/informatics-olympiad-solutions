#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    freopen("partyin.txt", "r", stdin);
    freopen("partyout.txt", "w", stdout);

    int n, m, a, b, x, y;
    cin >> n >> m >> a >> b;
    
    map <int, set <int>> nums;
    set <int> emptyset;

    for (int i = 1; i <= n; i++) {
        nums[i] = emptyset;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        nums[x].insert(y);
        nums[y].insert(x);
    }

    bool changed = true;
    vector <int> to_remove;

    while (changed) {
        changed = false;
        for (auto it: nums) {
            if (it.second.size() < a || n - it.second.size() - 1 < b) {
                changed = true;
                to_remove.push_back(it.first);
            }
        }

        for (int i : to_remove) {
            if (nums.find(i) != nums.end()) {
                n--;
                for (int j : nums[i]) {
                    nums[j].erase(i);
                }
                nums.erase(i);
            }
        }
    }

    cout << n;

}
