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
    vi n_arr(n);
    for (auto &x: n_arr) cin >> x;

    auto min_l = min_element(n_arr.begin(), n_arr.end());
    auto min_r = min_element(n_arr.rbegin(), n_arr.rend());

    // cout << &(*min_l) << "\n";
    // cout << *min_l << "\n";

    ll int a = *min_l;

    for (auto &it: n_arr) {
        it -= a;
    }

    ll int l = 0;
    ll int l2 = 0;

    for (auto &it: n_arr) {
        if (it > 0) {
            l++;
        } else {
            l2 = max(l2, l);
            l = 0;
        }

    }

    ll int ans = a * n;
    ll int l1 = (min_l - begin(n_arr)) + ((end(n_arr) - 1) - (min_r.base() - 1));
    
    cout << ans + max(l1, l2) << endl;

    return 0;
}
