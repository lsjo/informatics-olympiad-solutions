#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m;

    freopen("shopin.txt", "r", stdin);
    freopen("shopout.txt", "w", stdout);

    cin >> n >> m;

    int houses[n];
    int shops[m];
    int prices[m];
    int pricesright[m];
    int pricesleft[m];
    int minbadness[n];

    for (int i=0; i < n; i++) {cin >> houses[i];}
    for (int i=0; i < m; i++) {cin >> shops[i];}
    for (int i=0; i < m; i++) {cin >> prices[i];}

    for (int i=0; i < m; i++) {
        if (i == 0) {
            pricesleft[i] = prices[i] - shops[i];
        }

        else {
            pricesleft[i] = min(pricesleft[i-1], prices[i]-shops[i]);
        }
    }
    
    for (int i=m-1; i >= 0; i--) {
        if (i == m-1) {
            pricesright[i] = prices[i] + shops[i];
        }

        else {
            pricesright[i] = min(pricesright[i+1], prices[i]+shops[i]);
        }
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (houses[i] < shops[j]) {
            minbadness[i] = 1000000040;
            continue;
        }

        else {
            while (j < m-1 and shops[j+1] <= houses[i]) {
                j++;
            }
            minbadness[i] = houses[i] + pricesleft[j];
        }
    }

    j = m-1;

    for (int i = n-1; i >= 0; i--) {
        if (houses[i] > shops[j]) {
            continue;
        }

        else {
            while (j > 0 and shops[j-1] >= houses[i]) {
                j--;
            }

            minbadness[i] = min(minbadness[i], pricesright[j]-houses[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << minbadness[i] << " ";
    }

    return 0;
}
