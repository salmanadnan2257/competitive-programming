// --------- Game with Multiset ---------

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

int main() {
    map<ll, ll> ma, val;
    ma[0] = 1ll;
    for (ll i = 1ll; i < 30; i++) {
        ma[i] = ma[i-1ll]*2ll;
    }

    ll n, a, b;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) {
            val[ma[b]]++;
        } else {
            for (ll i = 30; i >= 0; i--) {
                if (b >= ma[i] && b != 0) {
                    if (val[ma[i]]) {
                        b -= min(b/ma[i], val[ma[i]]) * ma[i];
                    }
                }

            }
            if (b == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }

        if (i == n-1) {
            return 0;
        }
    }

    // int _;
    // _ = 1;
    // // cin >> _;
    // while (_--) {}

    return 0;
}
