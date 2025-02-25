#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
    int n; cin >> n;
    int dists[n+1], predists[n+2];
    predists[0] = 0;
    predists[1] = 0;
 
    unordered_map <int, vector <pair <int, int>>> agraph, bgraph;
 
    for (int i = 1; i < n; i++) {
        cin >> dists[i];
        agraph[i+1].push_back({i, dists[i]});
        agraph[i].push_back({i+1, dists[i]});
        bgraph[i+1].push_back({i, dists[i]});
        bgraph[i].push_back({i+1, dists[i]});
        predists[i+1] = predists[i]+dists[i];
    }
 
    int a; cin >> a;
    for (int i = 0; i < a; i++) {
        int x, k; cin >> x >> k;
        agraph[1].push_back({x, k});
        agraph[x].push_back({1, k});
    }
 
    int b; cin >> b;
    for (int i = 0; i < b; i++) {
        int x, k; cin >> x >> k;
        bgraph[n].push_back({x, k});
        bgraph[x].push_back({n, k});
    }
 
    int adist[n+1], bdist[n+1];
    for (int i = 0; i <= n; i++) {
        adist[i] = 1000000000000000000;
        bdist[i] = 1000000000000000000;
    }
 
    set <pair <int, int>> to_visit;
    to_visit.insert({0, 1});
    
    while (! to_visit.empty()) {
        auto x = *to_visit.begin();
        to_visit.erase(to_visit.begin());
 
        if (adist[x.second] < x.first) {continue;}
        adist[x.second] = x.first;
 
        for (pair <int, int> node : agraph[x.second]) {
            if (adist[node.first] > node.second+x.first) {
                to_visit.insert({node.second+x.first, node.first});
            }
        }
    }
 
    to_visit.clear();
    to_visit.insert({0, n});
 
    while (! to_visit.empty()) {
        auto x = *to_visit.begin();
        to_visit.erase(to_visit.begin());
 
        if (bdist[x.second] < x.first) {continue;}
        bdist[x.second] = x.first;
 
        for (pair <int, int> node : bgraph[x.second]) {
            if (bdist[node.first] > node.second+x.first) {
                to_visit.insert({node.second+x.first, node.first});
            }
        }
    }
 
    int crossdist = predists[n];
    for (int i = 1; i <= n; i++) {
        crossdist = min(crossdist, adist[i]+bdist[i]);
    }
 
    int q; cin >> q;
    
    for (int z = 0; z < q; z++) {
        int s, e; cin >> s >> e;
        vector <int> nums = {adist[s]+adist[e], bdist[s]+bdist[e], 
            predists[max(s, e)]-predists[min(s, e)], adist[s]+bdist[e]+crossdist,
            adist[e]+bdist[s]+crossdist};
        int maxdist = 1000000000000000000;
        for (auto x : nums) maxdist = min(maxdist, x);
        cout << maxdist << "\n";
    }
    
    return 0;
}
