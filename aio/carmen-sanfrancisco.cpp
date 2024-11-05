// NOTE: AS OF 5/11/24, THIS CODE RUNS VERY CLOSE TO THE TIME LIMIT,
// AND THERE'S A CHANCE THAT IT MAY GO OVER IN SOME CASES (hasn't happened to me yet though)

#include <unordered_set>
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    freopen("wherein.txt", "r", stdin);
    freopen("whereout.txt", "w", stdout);

    int n, m, a, b, c, q;
    cin >> n >> m;
    unordered_map <int, unordered_map <int, unordered_set <int>>> transport;
    unordered_set <int> cities;
    unordered_set <int> citiestemp;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (transport.count(c) > 0) {
            transport[c][a].insert(b);
            transport[c][b].insert(a);
        }

        else {
            transport[c] = {{a, {b,}}};
            transport[c].insert({b, {a,}});
        }
    }

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        if (i == 0) {
            cin >> a;
            b = transport[a].size();

            auto q = transport[a].begin();

            while (q != transport[a].end()) {
                cities.insert(q->first);
                q++;
            }
        }

        else {
            cin >> a;
            citiestemp.clear();
            for (auto it = cities.begin(); it != cities.end(); it++) {
                if (transport[a].count(*it) > 0) {
                    citiestemp.insert(transport[a][*it].begin(), transport[a][*it].end());
                }
            }

            cities = citiestemp;
        }
    }

    auto p = cities.begin();
    while (p != cities.end()) {
        cout << *p;
        p++;
        if (p != cities.end()) {
            cout << "\n";
        }
    }

    if (cities.size() == 0) {
        cout << "Impossible";
    }

    return 0;
    }
