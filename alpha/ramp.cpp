#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int maximum = 1;
    long long current;
    long long last;
    int score = 1;
 
    for (int i = 0; i < n; i++) {
        cin >> current;
        if (i != 0) {
            if (current == last + 1) {
                score += 1;
                maximum = max(maximum, score);
            }
 
            else {
                score = 1;
            }
        }
        last = current;
    }
 
    cout << maximum;
    return 0;
}
