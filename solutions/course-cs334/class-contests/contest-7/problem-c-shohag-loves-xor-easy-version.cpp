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
        // int n = 6;
        long long x, k;
        cin >> x >> k;
        
        // vi ans;
        long long count = 0;
        // for i >= 2x, x ^ i is larger than x and too large to divide i, so stop there
        long long lim = min(k, 2 * x);
        for (long long i = 1; i <= lim; i++) {
            long long check = x ^ i;
            if (x != i && ((x % check == 0) || (i % check == 0))) {
                // ans.emplace_back(i);
                count++;
            }
        }

        cout << count << "\n";
    }
}
