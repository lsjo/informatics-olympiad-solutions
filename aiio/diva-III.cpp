#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("divain.txt", "r", stdin);
    freopen("divaout.txt", "w", stdout);
 
    int n, t;
    cin >> n >> t;
 
    long long change_factor = 0;
    long long skill = 0;
    long long maxskill = 0;
 
    int musicians[n+1];
 
    for (int i = 0; i < n+1; i++) {
        musicians[i] = 0;
    }
 
    vector <pair <int, pair <int, int>>> changes;
    
    int k;
    cin >> k;
 
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        changes.push_back({a, {b, c}});
    }
    int j = 0;
    int day = 0;
    long long diff = 0;
 
    for (int i = 0; i < t+1; i++) {
        if (j != changes.size()) {
        while (changes[j].first == i) {
            if (j == changes.size()) {
                break;
            }
            diff -= musicians[changes[j].second.first];
            musicians[changes[j].second.first] = changes[j].second.second;
            diff += changes[j].second.second;
            j++;
        }
        }
 
        skill += diff;
        if (skill >= maxskill) {
            maxskill = skill;
            day = i;
        }
 
    }
 
    cout << day << " " << maxskill;
 
 
 
    return 0;
}
