#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int n, a, b; cin >> n >> a >> b;
    int heights[n+1];
    int dists[n+1];
 
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
        dists[i] = 100000000000000000;
    }
    int m; cin >> m;
    map <int, vector <int>> graph;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    set <pair <pair <int, int>, pair <int, int>>> to_visit;
    to_visit.insert({{0, 1}, {0, 0}});
 
    set <int> visited;
 
    while (! to_visit.empty()) {
        auto nums = *to_visit.begin();
        int node = nums.first.second;
        int x = nums.second.first;
        int y = nums.second.second;
        to_visit.erase(to_visit.begin());
        if (! visited.count(nums.first.second) && (x <= a && y <= b)) {
            visited.insert(node);
            for (int w : graph[node]) {
                if (heights[w] > heights[node]) {
                    int dist = x + y + heights[w]-heights[node];
                    to_visit.insert({{dist, w}, {heights[w]-heights[node]+x, y}});
                }
                else {
                    int dist = x + y + heights[node]-heights[w];
                    to_visit.insert({{dist, w}, {x, heights[node]-heights[w]+y}});
                }
            }
        }
    }
 
    cout << visited.size();
    return 0;
}
