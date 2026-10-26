#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y,z) for (int x = y; x >= z; x--)
#define ll long long
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

int main() {
    int _;
    cin >> _;

    while (_--) {
        ll n, m;
        cin >> n >> m;

        ll l = max(n-m, (ll)0);
        ll r = n + m;

        ll ans = 0;

        for (ll i=0; i<31; i++) {
            ll bit = 1LL << i;
            if ((l & bit) == 0) {
                // the smallest value >= l that has bit i set
                ll check = ((l >> i) | 1) << i;
                if (check <= r) ans |= bit;
            } else {
                ans |= bit;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}


