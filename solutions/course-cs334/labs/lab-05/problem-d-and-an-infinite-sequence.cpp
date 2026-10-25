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

        ll inc = 0;
        ll ans = 0;

        for (ll i=0; i<31; i++) {
            if (((1 << i) & 1) == 0) {
                ll check = (l | (1 << i)) - inc;
                if (check <= r) ans |= (1 << i);
            } else {
                ans |= (1 << i);
                inc |= (1 << i);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}


