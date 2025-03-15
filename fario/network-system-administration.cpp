#include <bits/stdc++.h>
 
using namespace std;
 
unordered_map <int, int> nodenumset, nodeset, setnodenum;
unordered_map <int, unordered_set <int>> sets;
 
void merge(int x, int y) {
    int a = nodenumset[x];
    int b = nodenumset[y];
    if (sets[a].size() > sets[b].size()) {
        for (int q : sets[b]) {
            nodeset[q] = a;
            sets[a].insert(q);
        }
        sets[b].clear();
        nodenumset[y]=a;
        setnodenum[a]=y;
 
        nodenumset[x]=b;
        setnodenum[b]=x;
    }
    else {
        for (int q : sets[a]) {
            nodeset[q] = b;
            sets[b].insert(q);
        }
        sets[a].clear();
        nodenumset[y] = b;
        setnodenum[b] = y;
 
        nodenumset[x] = a;
        setnodenum[a] = x;
    }
}
 
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        sets[i+1] = {i+1};
        nodeset[i+1] = i+1;
        nodenumset[i+1] = i+1;
        setnodenum[i+1] = i+1;
    }
    for (int q = 0; q < m; q++) {
        char x; cin >> x;
        if (x == 'E') {
            int a, b; cin >> a >> b;
            merge(a, b);
        }
        else {
            int a; cin >> a;
            a = nodeset[a];
            cout << setnodenum[a] << "\n";
        }
    }
    return 0;
}
