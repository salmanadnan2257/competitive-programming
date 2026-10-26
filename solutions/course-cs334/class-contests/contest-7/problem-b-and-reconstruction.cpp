#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y) for (int x = y; x >= 1; x--)

int main() {
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vi a(n-1), b(n);
        
        rep(i, 0, n-1) {
            cin >> a[i];
            b[i] = a[i];
        }

        bool found = true;
        rep(i, 0, n-1) {
            b[i+1] |= a[i];
            if ((b[i] & b[i+1]) != a[i]) {
                cout << "-1\n";
                found = false;
                break;
            }
        }

        if (found) {
            for (auto &x: b) cout << x << " ";
            cout << "\n";
        }
    }
}
