#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a, b, num;
    vector <int> to_visit;
    int visitable = 0;
 
    unordered_map <int, unordered_set <int>> forwardpaths;
    unordered_map <int, unordered_set <int>> backpaths;
 
    unordered_set <int> from_front;
    unordered_set <int> from_back;
 
    unordered_set <int> emptyset;
 
    for (int i = 0; i < n; i++) {
        forwardpaths[i+1] = emptyset;
        backpaths[i+1] = emptyset;
 
    }
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        forwardpaths[a].insert(b);
        backpaths[b].insert(a);
    }
 
    to_visit.push_back(1);
    from_front.insert(1);
 
    while (! to_visit.empty()) {
        num = to_visit.back();
        to_visit.pop_back();
        for (const auto& q: forwardpaths[num]) {
            if (! from_front.count(q)) {
                from_front.insert(q);
                to_visit.push_back(q);
            }
        }
    }
 
    to_visit.clear();
    from_back.insert(n);
    to_visit.push_back(n);
 
    while (! to_visit.empty()) {
        num = to_visit.back();
        if (from_front.count(num)) {
            visitable ++;
        }
        to_visit.pop_back();
        for (const auto& q: backpaths[num]) {
            if (! from_back.count(q)) {
                from_back.insert(q);
                to_visit.push_back(q);
            }
        }
    }
 
    cout << visitable;
 
    return 0;
}
