#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
int main() {
 
    freopen("busin.txt", "r", stdin);
    freopen("busout.txt", "w", stdout);
    
    int n, k, a;
 
    cin >> n >> k;
 
    int skills[n];
 
    vector <int> games;
    unordered_set <int> to_visit;
    unordered_map <int, int> counts;
 
    int count = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
        games.push_back(i);
    }
 
    for (int i = 0; i < k; i++) {
        cin >> a;
        to_visit.insert(a-1);
        counts[i-1] = 0;
    }
 
    int i = 0;
 
    while (i < 2*(n-1)) {
        if (skills[games[i]] > skills[games[i+1]]) {
            games.push_back(games[i]);
        }
        else {
            games.push_back(games[i+1]);
        }
 
        if (to_visit.count(games[i]) && to_visit.count(games[i+1])) {
            if (counts[games[i]] == 0 && counts[games[i+1]] == 0) {
                counts[games[i]] = 2;
                counts[games[i+1]] = 2;
                count ++;
            }
            else if ((counts[games[i]] == 1 && counts[games[i+1]] == 0) || (counts[games[i]] == 0 && counts[games[i+1]] == 1)) {
                counts[games[i]] = 2;
                counts[games[i+1]] = 2;
            }
            else if (counts[games[i]] == 1 && counts[games[i+1]] == 1) {
                counts[games[i]] = 2;
                counts[games[i+1]] = 2;
                count --;
            }
        }
 
        else if (to_visit.count(games[i])) {
            if (counts[games[i]] == 0) {
                counts[games[i]] = 1;
                count ++;
            }
        }
 
        else if (to_visit.count(games[i+1])) {
            if (counts[games[i+1]] == 0) {
                counts[games[i+1]] = 1;
                count ++;
            }
        }
        i += 2;
    }
    cout << count;
    return 0;
}
