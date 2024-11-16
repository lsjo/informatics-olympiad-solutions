#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    freopen("oilin.txt", "r", stdin);
    freopen("oilout.txt", "w", stdout);

    int r, c, k, a, b, q;
    cin >> r >> c >> k;

    char map[r][c];
    int vis[r][c];
    queue <int> rows;
    queue <int> cols;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            vis[i][j] = 100000001;
            if (map[i][j] == '$') {
                vis[i][j] = 0;
                rows.push(i);
                cols.push(j);
            }
        }
    }

    while (! rows.empty()) {
        a = rows.front();
        b = cols.front();
        rows.pop();
        cols.pop();

        if (map[a][b] == '.') {
            map[a][b] = '*';
        }

        if (vis[a][b] < k) {
            if (a > 0) {
                if (map[a-1][b] != '#' && vis[a-1][b] > vis[a][b]+1) {
                    rows.push(a-1);
                    cols.push(b);
                    vis[a-1][b] = vis[a][b] + 1;
                }
            }
            if (a < r-1) {
                if (map[a+1][b] != '#' && vis[a+1][b] > vis[a][b] + 1) {
                    rows.push(a+1);
                    cols.push(b);
                    vis[a+1][b] = vis[a][b] + 1;
                }
            }

            if (b > 0) {
                if (map[a][b-1] != '#' && vis[a][b-1] > vis[a][b] + 1) {
                    rows.push(a);
                    cols.push(b-1);
                    vis[a][b-1] = vis[a][b] + 1;
                }
            }

            if (b < c-1) {
                if (map[a][b+1] != '#' && vis[a][b+1] > vis[a][b] + 1) {
                    rows.push(a);
                    cols.push(b+1);
                    vis[a][b+1] = vis[a][b] + 1;
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        if (i < r-1) {
            cout << "\n";
        }            
    }
    return 0;
}
