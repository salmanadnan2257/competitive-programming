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
    int n, q;
    cin >> n >> q;
    vlli arr(n, 0);
    vlli fre(n, 0);
    for (auto &x: arr) cin >> x;

    int l, r;
    rep(i, 0, q) {
        cin >> l >> r;
        // cout << l << " " << r << "\n";
        fre[l-1]++;
        if (r < n) {
            fre[r]--;
        }
        // cout << fre[l] << " " << fre[r+1] << "\n";
    }
    rep(i, 1, n) {
        fre[i] += fre[i-1];
    }

    sort(arr.begin(), arr.end());
    sort(fre.begin(), fre.end());
    // for (auto &x: arr) cout << x << " ";cout << "\n";
    // for (auto &x: fre) cout << x << " ";cout << "\n";

    lli ans = 0;
    rep(i, 0, n) {
        ans += (fre[i] * arr[i]);
    }

    cout << ans << "\n";

    return 0;
}
