#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, r; cin >> n >> r;
    int maxdeg[n], deg[n];
    unordered_map <int, set <int>> graph;
    for (int i = 0; i < n; i++) {
        cin >> maxdeg[i];
        deg[i] = 0;
    }
    for (int i = 0; i < r; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        deg[a]++;
        deg[b]++;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector <pair <int, int>> edges;
    set <pair <int, int>> nodes;
    for (int i = 0; i < n; i++) {
        nodes.insert({deg[i]-maxdeg[i], i});
    }
 
    bool pos = true;
 
    while (! nodes.empty()) {
        auto p = *nodes.begin();
        nodes.erase(p);
        if (p.first > 0) {
            pos = false;
            break;
        }
        for (auto a : graph[p.second]) {
            edges.push_back({p.second, a});
            graph[a].erase(p.second);
            nodes.erase({deg[a]-maxdeg[a], a});
            deg[a]--;
            nodes.insert({deg[a]-maxdeg[a], a});
        }
    }
 
    if (! pos) {cout << "IMPOSSIBLE\n";}
    else {
        for (auto x : edges) cout << x.first+1 << " " << x.second+1 << "\n";
    }
    return 0;
}
