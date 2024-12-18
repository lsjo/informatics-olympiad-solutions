#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("leakin.txt", "r", stdin);
    freopen("leakout.txt", "w", stdout);
 
    int n, k, a;
    cin >> n >> k;
 
    int subs[n];
 
    for (int i = 0; i < n; i++) {
        cin >> subs[i];
        subs[i]--;
    }
 
    set <long long> nums;
    for (int i = 0; i < k; i++) {
        cin >> a;
        nums.insert(a-1);
    }
 
    long long minimum = 1;
 
    for (int x: nums) {
        int q = x;
        int transitions = 1;
        while (subs[x] != q) {
            transitions ++;
            x = subs[x];
        }
 
        long long a = minimum;
        long long b = transitions;
 
        while (a != 0 && b != 0) {
            if (a > b) {
                int r = a % b;
                a = b;
                b = r;
            }
            else {
                int r = b % a;
                a = a;
                b = r;
            }
        }
 
        int multiple = a + b;
        minimum = minimum * transitions / multiple;
    }
 
    cout << minimum;
    return 0;
}
