#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y,z) for (int x = y; x >= z; x--)
#define ll long long
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

int main() {
    int n;
    cin >> n;
    vi f_arr(n);
    vi s_arr(n);

    // for (auto &x: f_arr) cin >> x;
    // for (auto &x: s_arr) cin >> x;
    int x;
    rep(i, 0, n) {
        cin >> x;
        // cout << x << " " << i << "\n";
        f_arr[x-1] = i;
    }
    // for (auto &x: f_arr) cout << x << " ";
    // cout << "\n";

    rep(i, 0, n) {
        cin >> x;
        s_arr[x-1] = i;
    }
    // for (auto &x: s_arr) cout << x << " ";
    // cout << "\n";

    vi c(n);
    rep(i, 0, n) {
        c[f_arr[i]] = s_arr[i];
    }
    // for (auto &x: c) cout << x << " ";
    // cout << "\n";

    int ans=0, max=-1;
    rep(i, 0, n) {
        if (c[i] > max) {
            max = c[i];
        } else {
            ans++;
        }
    }

    cout << ans << "\n";
    // vi pos(n), c(n);
    // rep(i, 0, n) {
    //     pos[
    // }

    return 0;
}
