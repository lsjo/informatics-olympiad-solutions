#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    int currentheight = 0;
    int maxheight = 0;
    int time;
    int width;
    int height;
    vector <int> blocks;
    vector <int> ends;

    freopen("artin.txt", "r", stdin);
    freopen("artout.txt", "w", stdout);

    blocks.push_back(0);
    ends.push_back(100000000); // so the list will never be empty

    cin >> n;
    cin >> time >> width >> height;

    for (int i=0; i < 2000001; i++) {
        while (time >= ends.back()) {
            ends.pop_back();
            currentheight = currentheight - blocks.back();
            blocks.pop_back();
        }

        if (i == time and n != 0) {
            currentheight = currentheight + height;
            maxheight = max(maxheight, currentheight);
            blocks.push_back(height);
            ends.push_back(time+width);
            n--;
            if (n!= 0) {
            cin >> time >> width >> height; }
        }
    }

    std::cout << maxheight;
    return 0;
}
