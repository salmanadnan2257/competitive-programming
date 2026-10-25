#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define ll long long

int main() {
    int t;
    cin >> t;
    vi a(t);
    ll s = 0;
    int x = 0;
    rep(i, 0, t) {
        cin >> x;
        s += x;
        a[i] = x;
        // cout << a[i] << "\n";
    }

    if (s == 360) {
        cout << "YES" << "\n";
        return 0;
    } else {
        int not_found = true;
        rep(i, 0, (1<<t)) {
            s = 0;
            rep(j, 0, t) {
                if (i & (1<<j)) {
                    s += a[j];
                } else {
                    s -= a[j];
                }
            }
            if (s % 360 == 0) {
                cout << "YES";
                not_found=false;
                break;
            }
        }

        if (not_found) {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}
