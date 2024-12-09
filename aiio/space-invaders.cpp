#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("spacein.txt", "r", stdin);
    freopen("spaceout.txt", "w", stdout);
 
    int w, h;
    cin >> w >> h;
    int k;
    cin >> k;
 
    vector <pair <int, int>> events;
 
    for (int i = 0; i < k; i++) {
        int s, a, q;
        cin >> s;
 
        int l = 1000000010;
        int r = -1;
 
        for (int j = 0; j < s; j++) {
            cin >> a >> q;
            l = min(l, a);
            r = max(r, a);
        }
 
        events.push_back({l, 1});
        events.push_back({r, -1});
    }
 
    sort(events.begin(), events.end());
 
    int uncovered = 0;
    int count = 0;
    int last = 0;
 
    for (pair <int, int> x : events) {
        if (count == 0) {
            uncovered += x.first - last;
        }
        if (x.second == -1) {
            count --;
        }
 
        else {
            count ++;
        }
 
        last = x.first;
    }
 
    uncovered += w - last;
 
    cout << uncovered;
 
    
}
