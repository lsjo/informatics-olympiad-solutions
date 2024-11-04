#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, p, a, b, start, zcount, ocount, last, x;
    int c = 0;
    int total = 0;
    int answer = 0;

    freopen("arthin.txt", "r", stdin);
    freopen("arthout.txt", "w", stdout);

    cin >> n >> p;
    vector <int> graph[n];
    int visited[n];
    int duellers[n];
    vector <int> visit;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        duellers[i] = 0;
    }

    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        duellers[a-1] = 1;
        duellers[b-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (duellers[i] == 1) {
            visited[i] = 1;
            duellers[i] = 2;
            start = i;
            ocount = 1;
            zcount = 0;
            last = 0;
            visit.push_back(start);

            while (! visit.empty()) {
                start = visit.back();
                last = duellers[start];
                visit.pop_back();
                x = graph[start].size();
                for (int m = 0; m < x; m++) {
                    if (duellers[graph[start][m]] == 1) {
                    if (last == 2) {
                        duellers[graph[start][m]] = 3;
                        zcount ++;
                        visit.push_back(graph[start][m]);
                    }

                    else {
                        duellers[graph[start][m]] = 2;
                        ocount ++;
                        visit.push_back(graph[start][m]);
                    }
                    }
                }
            }

            total += ocount + zcount;
            answer += max(ocount, zcount);
        }
    }

    answer += n - total;
    cout << answer;

}
