#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[1005][1005];
 
int main() {
    int r, c, t; cin >> r >> c >> t;
    int arr[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    }
 
    int tasks[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) tasks[i][j] = 0;
    }
 
    for (int i = 0; i < t; i++) {
        int a, b, x; cin >> a >> b >> x;
        tasks[a-1][b-1]=x;
    }
 
    int templex, templey;
    cin >> templex >> templey;
 
    set <pair <int, pair <int, int>>> to_visit;
    multiset <int> pq;
 
    to_visit.insert({0, {0, 0}});
    int cscore = 0;
    int count = 0;
 
    while (! to_visit.empty()) {
        auto x = *to_visit.begin();
        to_visit.erase(to_visit.begin());
 
        if (visited[x.second.first][x.second.second]) continue;
        bool broken = false;
        
        while (x.first > cscore) {
            if (pq.empty()) {
                broken = true;
                break;
            }
            else {
                count++;
                int a = *pq.rbegin();
                cscore += a;
                pq.erase(pq.find(a));
            }
        }
 
        if (broken) break;
 
        if (tasks[x.second.first][x.second.second] != 0) {
            pq.insert(tasks[x.second.first][x.second.second]);
        }
 
        visited[x.second.first][x.second.second] = true;
        if (x.second.first == templex-1 && x.second.second==templey-1) break;
        if (x.second.first > 0 && (! visited[x.second.first-1][x.second.second])) {
            to_visit.insert({arr[x.second.first-1][x.second.second], {x.second.first-1, x.second.second}});
        }
        if (x.second.first < r-1 && (! visited[x.second.first+1][x.second.second])) {
            to_visit.insert({arr[x.second.first+1][x.second.second], {x.second.first+1, x.second.second}});
        }
        if (x.second.second > 0 && (! visited[x.second.first][x.second.second-1])) {
            to_visit.insert({arr[x.second.first][x.second.second-1], {x.second.first, x.second.second-1}});
        }
        if (x.second.second < c-1 && (! visited[x.second.first][x.second.second+1])) {
            to_visit.insert({arr[x.second.first][x.second.second+1], {x.second.first, x.second.second+1}});
        }
    }
 
    if (visited[templex-1][templey-1]) cout << count;
    else cout << -1;

    return 0;
}
