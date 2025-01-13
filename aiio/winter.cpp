#include <bits/stdc++.h>

using namespace std;

#define int long long

unordered_map <int, vector<int>> graph;

int arr[100005], total[100005];
bool seen[100005];

int maxnum = -1000000000000;

int dfs(int x) {
    int curr = arr[x];
    seen[x] = true;
    for (int a : graph[x]) {
        if (! seen[a]) {
            int num = dfs(a);
            if (num > 0) {
                curr += num;
            }
        }
    }

    total[x] = curr;
    maxnum = max(maxnum, total[x]);
    return total[x];
}

signed main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << maxnum;
    return 0;
}
