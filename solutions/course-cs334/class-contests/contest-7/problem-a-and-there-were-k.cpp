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
        // int check = n;
        double ans = 0;
        // per(i, n-1) {
        //     check = check & i;
        //     cout << i << " " << check << "\n";
        //     if (check == 0) {
        //         ans = i;
        //         break;
        //     }
        // }
        ans = floor(log2(n));
        // cout << ans << "\n";
        // cout << (1<<ans) << "\n";
        ans = pow(2.0, ans) - 1;
        cout << static_cast<int>(ans) << "\n";
        // cout << (65 & 64 & 62) << "\n";
        // cout << "\n";
    }
}
