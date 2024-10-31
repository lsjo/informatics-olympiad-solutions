#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int b, n;
    vector <tuple<int, int>> heights;
    int num;
    tuple <int, int> place;
    int total = 0;
    int levels = 0;

    freopen("tennisin.txt", "r", stdin);
    freopen("tennisout.txt", "w", stdout);

    cin >> b >> n;

    for (int i = 0; i < b; i++) {
        cin >> num;
        heights.push_back({num, i});
    }

    std::sort(heights.begin(), heights.end());
    std::reverse(heights.begin(), heights.end());

    while (n > total + (get<0>(heights.back()) - levels)*heights.size()) {
        num = get<0>(heights.back());

        total += (num - levels) * heights.size();
        levels = num;

        while (get<0>(heights.back()) == num) {
            heights.pop_back();
        }
    }

    int remainder = n - total;
    int x = (remainder - 1) % heights.size();
    int length = heights.size();
    vector<int> indices;

    for (int i = 0; i < length; i++) {
        indices.push_back(get<1>(heights[i]));
    }

    std::sort(indices.begin(), indices.end());

    cout << indices[x] + 1;

    return 0;

}
