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
        int x, k;
        cin >> x >> k;
        
        // vi ans;
        int count;
        rep(i, 1, k+1) {
            int check = x ^ i;
            if (x != i && ((x % check == 0) || (i % check == 0))) {
                // ans.emplace_back(i);
                count++;
            }
        }

        cout << count << "\n";
    }
}
