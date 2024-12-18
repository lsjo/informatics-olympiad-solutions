#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int main() {
    int r, c, n;
    cin >> r >> c >> n;
 
    int startx = 0;
    int starty = 0;
 
    set <pair <int, int>> positions;
    map <pair <int, int>, int> vis;
    map <pair <int, int>, char> last;
 
    positions.insert({0, 0});
 
    int lastx, lasty;
 
    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir;
 
        if (dir == 'N') {starty--; positions.insert({startx, starty});}
        else if (dir == 'S') {starty++; positions.insert({startx, starty});}
        else if (dir == 'E') {startx++; positions.insert({startx, starty});}
        else if (dir == 'W') {startx--; positions.insert({startx, starty});}
 
        vis[{startx, starty}] = -1;
 
        if (i == n-1) {
            lastx = startx;
            lasty = starty;
        }
 
    }
 
    queue <pair <int, int>> to_visit;
    to_visit.push({0, 0});
    vis[{0, 0}] = 0;
 
    while (! to_visit.empty()) {
        int cx, cy;
        cx = to_visit.front().first;
        cy = to_visit.front().second;
        to_visit.pop();
 
        if (positions.count({cx-1, cy}) && vis[{cx-1, cy}] == -1) {
            vis[{cx-1, cy}] = vis[{cx, cy}] + 1;
            last[{cx-1, cy}] = 'W';
            to_visit.push({cx-1, cy});
        }
 
        if (positions.count({cx+1, cy}) && vis[{cx+1, cy}] == -1) {
            vis[{cx+1, cy}] = vis[{cx, cy}] + 1;
            last[{cx+1, cy}] = 'E';
            to_visit.push({cx+1, cy});
        }
 
        if (positions.count({cx, cy-1}) && vis[{cx, cy-1}] == -1) {
            vis[{cx, cy-1}] = vis[{cx, cy}] + 1;
            last[{cx, cy-1}] = 'N';
            to_visit.push({cx, cy-1});
        }
 
        if (positions.count({cx, cy+1}) && vis[{cx, cy+1}] == -1) {
            vis[{cx, cy+1}] = vis[{cx, cy}] + 1;
            last[{cx, cy+1}] = 'S';
            to_visit.push({cx, cy+1});
        }
    }
 
    cout << vis[{lastx, lasty}] << "\n";
    vector <char> list;
 
    while (lastx != 0 || lasty != 0) {
        if (last[{lastx, lasty}] == 'N') {
            list.push_back('S');
            lasty ++;
        }
        else if (last[{lastx, lasty}] == 'S') {
            list.push_back('N');
            lasty--;
        }
        else if (last[{lastx, lasty}] == 'E') {
            list.push_back('W');
            lastx --;
        }
        else if (last[{lastx, lasty}] == 'W') {
            list.push_back('E');
            lastx ++;
        }
    }
 
 
    for (char x : list) {
        cout << x;
    }
 
 
    return 0;
}
