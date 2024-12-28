#include <bits/stdc++.h>
 
#define int long long
 
long long adist[100005], cdist[100005];
bool visa[100005], visb[100005], visc[100005];
int acount[100005], bcount[100005], ccount[100005];
long long bdist[100005];
int anum[100005], bnum[100005], cnum[100005];
 
using namespace std;
 
signed main() {
    int n, m;
    cin >> n >> m;
 
    unordered_map <int, vector <pair <int, int>>> graph;
 
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
 
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
 
    }
 
    for (int i = 1; i <= n; i++) {
        adist[i] = -1;
        bdist[i] = -1;
        cdist[i] = -1;
    }
 
    priority_queue <pair <int, int>, vector <pair<int, int>>, greater<pair <int, int>>> edges;
    edges.push({0, 1});
    adist[1] = 0;
    acount[1] = 1;
 
    while (! edges.empty()) {
        pair <int, int> current = edges.top();
        current.first = current.first;
        edges.pop();
 
        if (visa[current.second]) continue;
        visa[current.second] = true;
 
        for (pair <int, int> x : graph[current.second]) {
            if (adist[x.first] != -1) {
                if (adist[current.second] + x.second < adist[x.first]) {
                    adist[x.first] = adist[current.second] + x.second;
                    edges.push({adist[x.first], x.first});
                    acount[x.first] = acount[current.second] % 1000000007;
                }
                else if (adist[current.second]+x.second == adist[x.first]) {
                    acount[x.first] = (acount[x.first] + acount[current.second]) % 1000000007;
                }
            }
            else {
                adist[x.first] = adist[current.second] + x.second;
                edges.push({adist[x.first], x.first});
                acount[x.first] = acount[current.second] % 1000000007;
            }
        }
    }
 
    priority_queue <pair <int, int>, vector <pair<int, int>>, greater<pair <int, int>>> bedges;
    bedges.push({0, 2});
    bdist[2] = 0;
    bcount[2] = 1;
 
    while (! bedges.empty()) {
        pair <int, int> current = bedges.top();
        current.first = current.first;
        bedges.pop();
 
        if (visb[current.second]) continue;
        visb[current.second] = true;
 
        for (pair <int, int> x : graph[current.second]) {
            if (bdist[x.first] != -1) {
                if (bdist[current.second] + x.second < bdist[x.first]) {
                    bdist[x.first] = bdist[current.second] + x.second;
                    bedges.push({bdist[x.first], x.first});
                    bcount[x.first] = bcount[current.second] % 1000000007;
                }
                else if (bdist[current.second] + x.second == bdist[x.first]) {
                    bcount[x.first] = (bcount[current.second]+bcount[x.first]) % 1000000007;
                }
            }
            else {
                bdist[x.first] = bdist[current.second] + x.second;
                bedges.push({bdist[x.first], x.first});
                bcount[x.first] = bcount[current.second] % 1000000007;
            }
        }
    }
 
    priority_queue <pair <int, int>, vector <pair<int, int>>, greater<pair <int, int>>> cedges;
    cedges.push({0, n});
    cdist[n] = 0;
    ccount[n] = 1;
 
    while (! cedges.empty()) {
        pair <int, int> current = cedges.top();
        current.first = current.first;
        cedges.pop();
 
        if (visc[current.second]) continue;
        visc[current.second] = true;
 
        for (pair <int, int> x : graph[current.second]) {
            if (cdist[x.first] != -1) {
                if (cdist[current.second] + x.second < cdist[x.first]) {
                    cdist[x.first] = cdist[current.second] + x.second;
                    cedges.push({cdist[x.first], x.first});
                    ccount[x.first] = ccount[current.second] % 1000000007;
                }
                else if (cdist[current.second] + x.second == cdist[x.first]) {
                    ccount[x.first] = (ccount[current.second]+ccount[x.first]) % 1000000007;
                }
            }
            else {
                cdist[x.first] = cdist[current.second] + x.second;
                cedges.push({cdist[x.first], x.first});
                ccount[x.first] = ccount[current.second] % 1000000007;
            }
        }
    }
 
    if (adist[n] != bdist[n]) {
        cout << 0 << "\n";
        cout << acount[n]*bcount[n];
    }
 
    else {
        long long mindist = 100000000000000;
        long long ways = 0;
 
        for (int i = 1; i <= n; i++) {
            if (adist[i] == bdist[i] && cdist[i]+adist[i]==bdist[n]) {
                if (mindist > adist[i]) {
                    mindist = adist[i];
                    ways = (acount[i]*bcount[i]*ccount[i]) % 1000000007;
                }
                else if (mindist == adist[i]) {
                    ways = (ways + acount[i]*bcount[i]*ccount[i]) % 1000000007;
                }
            }
        }
 
        cout << adist[n] - mindist << "\n";
 
        cout << ways << "\n";
    }
 
    
}
