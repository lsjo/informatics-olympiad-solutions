#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;

    int sections[n];
    int prefixes[n];
    int prefix = 0;

    for (int i = 0; i < n; i++) {
        cin >> sections[i];
        prefix += sections[i];
        prefixes[i] = prefix;
    }

    int losize = 0, hisize = 100000000000005;

    while (losize != hisize) {
        int midsize = (losize+hisize) / 2;
        int smaller = 0, larger = 0;

        for (int i = 0; i < n; i++) {
            int sub;
            if (i == 0) sub = 0;
            else sub = prefixes[i-1];

            int lo = i, hi = n-1;

            while (lo != hi) {
                int mid = (lo+hi) / 2;

                if (prefixes[mid]-sub > midsize) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            if (prefixes[lo]-sub > midsize) {
                larger += n - lo;
            }

            lo = i, hi = n-1;

            while (lo != hi) {
                int mid = (lo+hi+1) / 2;

                if (prefixes[mid]-sub < midsize) {
                    lo = mid;
                }
                else {
                    hi = mid - 1;
                }
            }

            if (prefixes[lo] - sub < midsize) {
                smaller += lo + 1;
            }
        }

        if (k <= larger) {losize = midsize + 1;}
        else if (n*(n+1)/2 - k < smaller) {hisize = midsize;}
        else {losize = midsize; hisize=midsize;}
    }

    cout << losize;

    return 0;
}
