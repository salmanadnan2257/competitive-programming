#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vlli vector<long long int>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y,z) for (int x = y; x >= z; x--)
#define ll long long
#define lli long long int
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

int count_bits(int x, int i) {
    int mx = (1 << (i+1));
    int mn = (1 << i);
    int count = (x/mx) * mn;
    int rem = x%mx;
    if (rem >= mn) count += rem-mn+1;
    return count;
}

int main() {
    int _;
    cin >> _;
    while (_--) {
        int l, r;
        cin >> l >> r;
        // int num = floor(log2(l+1));
        // // cout << num << "\n";
        // int check;
        // int ans = 0;
        // while (true) {
        //     num++;
        //     check = static_cast<int>(pow(2.0, static_cast<double>(num)));
        //     if (check <= r) {
        //         ans ++;
        //     } else {
        //         break;
        //     }
        // }
        // cout << ans << "\n";
        int n = r-l+1;
        int ans = n;

        for (int i=0; i<18; i++) {
            int r_bits = count_bits(r, i);
            int l_bits = count_bits(l-1, i);
            int total_bits = r_bits - l_bits;
            ans = min(ans, n-total_bits);
            // cout << i << " " << total_bits << " " << r_bits << " " << l_bits << " " << ans << "\n";
        }

        cout << ans << "\n";
    }

    return 0;
}

