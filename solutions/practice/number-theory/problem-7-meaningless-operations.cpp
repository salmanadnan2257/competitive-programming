// --------- Meaningless Operations ---------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}

int main() {
    int _ = 1;
    cin >> _;

    while (_--) {
        ll n;
        cin >> n;

        ll MSB = 63 - __builtin_clzll(n);
        // cout << MSB << " " << __builtin_clz(2) << "\n";
        ll po_two_mi_one = (1 << (MSB+1)) - 1;

        if (n != po_two_mi_one) {
            cout << po_two_mi_one << "\n";
        } else {
            ll best = 1;
            for (ll i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    best = max(best, n/i);
                }
            }
            cout << best << "\n";
        }
    }

    return 0;
}
