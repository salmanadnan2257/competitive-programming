// --------- Cat Cycle ---------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    cin >> _;
    while (_--) {
        int n, k;
        cin >> n >> k;
        --k;

        if (n % 2 == 0) {
            cout << 1 + (k % n) << "\n";
        } else {
            int isect = k / ((n-1) / 2);
            cout << 1 + ((k + isect) % n) << "\n";
        }
    }

    return 0;
}
