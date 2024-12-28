#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
 
#define int long long
 
using namespace std;
 
int found[100005];
int dist[1000005];
 
signed main() {
    int v, e, k;
    cin >> v >> e >> k;
 
    priority_queue <pair <int, pair <int, int>>, 
        vector<pair <int, pair <int, int>>>, 
        greater<pair <int, pair <int, int>>>> dists;
 
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        dists.push({0, {a, a}});
        found[a] = a;
        dist[a] = 0;
    }
 
    unordered_map <int, vector <pair <int, int>>> graph;
 
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
 
    int mindist = 10000000000;
 
    while (! dists.empty()) {
        pair <int, pair <int, int>> node = dists.top();
        dists.pop();
 
        if (found[node.second.first] == node.second.second && node.second.first != node.second.second) {
            continue;
        }
 
        if (found[node.second.first] != 0 && node.second.first != node.second.second) {
            mindist = min(mindist, node.first + dist[node.second.first]);
            if (dist[node.second.first] <= node.first) {
                continue;
            }
        }
 
        found[node.second.first] = found[node.second.second];
        dist[node.second.first] = node.first;
 
        for (pair <int, int> x : graph[node.second.first]) {
            if (found[x.first] != node.second.first) {
                dists.push({node.first + x.second, {x.first, node.second.second}});
            }
        }
    }
 
    cout << mindist << "\n";
 
    return 0;
}
