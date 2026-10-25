// --------- Floor and Mod ---------

// --- Solution 1 ---
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define all(v) v.begin(), v.end()
// #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}

// int main() {
//     int _ = 1;
//     cin >> _;

//     while (_--) {
//         ll x, y;
//         cin >> x >> y;

//         ll ans = 0;
//         for (ll k = 1; k < 50000; k++) {
//             ll lb = k + 2, rb = min(x / k, y + 1);
//             if (rb >= lb) ans += rb - lb + 1;
//         }

//         cout << ans << "\n";
//     }

//     return 0;
// }


// --- Solution 2 ---
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll _;
    cin >> _;
    while (_--) {
        ll x, y;
        cin >> x >> y;
        
        y = min(x-1, y);
        ll ans = 0;
        if (y <= 1) {
            cout << ans << endl;
            continue;
        }

        ll n = x;
        ll b;
        for (b=2; b*b <= n; b++) {
            if (b != n/b) {
                if (b <= y && b >= 2) {
                    ans += min((n/(b+1)), b-1);
                }

                if (n/b <= y && n/b >= 2) {
                    ans += min((n/((n/b)+1)),n/b-1);
                }
            } else {
                if (b <= y && b >= 2) {
                    ans += min(b, b-1);
                }
            }

            ll l = (n/b) + 1;
            ll h = min((n/(b-1))-1, y);
            if (l <= h) {
                ans += (h-l+1) * (b-1);
            }
        }

        // sqrt(n)
        b--;

        if (b != n/b && (b+1) != n/b) {
            ll num = b+1;
            if (num <= y) {
                ans += min(n/(num+1), num-1);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
