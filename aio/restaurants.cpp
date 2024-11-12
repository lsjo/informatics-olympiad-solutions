#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    freopen("restin.txt", "r", stdin);
    freopen("restout.txt", "w", stdout);
 
    int n;
    int arrsize;
    cin >> n;
    int countries[n];
 
    for (int i = 0; i < n; i++) {
        cin >> countries[i];
    }
 
    sort(countries, countries+n);
 
    int m;
    cin >> m;
    vector <int> restaurants;
    arrsize = m;
    int num;
    int total = 0;
    int j;
 
    for (int i = 0; i < m; i++) {
        cin >> num;
        restaurants.push_back(num);
    }
 
    sort(restaurants.begin(), restaurants.end());
    reverse(restaurants.begin(), restaurants.end());
 
    for (int i = 0; i < n; i++) {
        num = countries[i];
        j = 0;
        while (j < arrsize) {
            restaurants[j] --;
            if (restaurants[j] == 0) {
                restaurants.erase(restaurants.begin() + j);
                j--;
                arrsize --;
            }
            num --;
            if (num == 0) {
                break;
            }
            j++;
        }
        total += num;
    }
 
    cout << total;
    return 0;
}
