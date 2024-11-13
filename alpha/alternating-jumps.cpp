#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long ototal = 0;
    long long ztotal = 0;
    long long total = 0;
    int current;
    int last;
    bool start = true;
 
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (i == 0) {
            last = current;
        }
        if (current != last && start) {
            if (last == 0) {
                    ztotal ++;
                }
            else {
                    ototal ++;
                }
            start = false;
        }
 
        if (! start) {
            if (current == 1) {
                ototal += ztotal;
                ototal = ototal % 1000000007;
                total = ztotal; 
            }
 
            else {
                ztotal += ototal;
                ztotal = ztotal % 1000000007;
                total = ototal;
            }
        }
 
        last = current;
    }
 
    cout << total;
 
    return 0;
}
