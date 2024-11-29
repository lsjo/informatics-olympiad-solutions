#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("leftin.txt", "r", stdin);
    freopen("leftout.txt", "w", stdout);

    int T, a, b;
    cin >> T;

    pair <int, int> nums[10005];
    pair <int, int> dists[10005];

    for (int i = 0; i < 10005; i++) {
        nums[i].first = -1;
        nums[i].second = 1000000;
        dists[i] = {0, 0};
    }

    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        if (nums[a].first < b) {
            nums[a].first = b;
        }

        if (nums[a].second > b) {
            nums[a].second = b;
        }
    }

    int lasttop = -1;
    int lasttopdist = 0;
    int lastbottom = -1;
    int lastbottomdist = 0;
    int lasta = -1;
    int x, y;

    for (int i = 0; i < 10005; i++) {
        if (nums[i].first != -1) {
            if (lasta != -1) {
                dists[i].first = min(abs(nums[i].first-nums[lasta].first) + i-lasta + lasttopdist, abs(nums[i].first-nums[lasta].second) + i-lasta + lastbottomdist);
                dists[i].second = min(abs(nums[i].second-nums[lasta].first) + i-lasta + lasttopdist, abs(nums[i].second-nums[lasta].second) + i-lasta + lastbottomdist);
            }
            lasta = i;
            x = dists[i].first;
            dists[i].first = dists[i].second + abs(nums[i].first-nums[i].second);
            dists[i].second = x + abs(nums[i].first-nums[i].second);
            lasttop = nums[i].first;
            lastbottom = nums[i].second;
            lasttopdist = dists[i].first;
            lastbottomdist = dists[i].second;
        }
    }

    cout << min(lasttopdist, lastbottomdist);

    return 0;
}
