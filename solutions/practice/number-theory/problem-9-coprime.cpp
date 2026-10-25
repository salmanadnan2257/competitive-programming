// --------- Coprime ---------

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define endl "\n"

int main() {
    ll _;
    cin >> _;
    while (_--) {
        ll n;
        cin >> n;
        vll v(1001, 0);
        
        ll mx=-1;
        for (ll i=1; i <= n; ++i) {
            ll tmp;
            cin >> tmp;
            v[tmp] = i;
        }
        for (ll i=1; i<= 1000; ++i) {
            for (ll j=1; j <= 1000; ++j) {
                if (v[i] && v[j] && (ll)(__gcd(i, j) == 1)) {
                    mx = max(mx, v[i]+v[j]);
                }
            }
        }

        cout << mx << endl;
    }

    return 0;
}
