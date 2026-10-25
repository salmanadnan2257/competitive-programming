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
    vll n_arr(n);
    for(auto &x: n_arr) cin >> x;

    vll sum_n_arr = {0};
    rep(i, 0, n) {
        sum_n_arr.eb(sum_n_arr[i]+n_arr[i]);
    }

    vll sort_n_arr = n_arr;
    all(sort_n_arr);
    vll sum_sort_n_arr = {0};
    rep(i, 0, n) {
        sum_sort_n_arr.eb(sum_sort_n_arr[i]+sort_n_arr[i]);
    }

    int m;
    cin >> m;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << (sum_n_arr[r] - sum_n_arr[l-1]) << "\n";
        } else {
            cout << (sum_sort_n_arr[r] - sum_sort_n_arr[l-1]) << "\n";
        }
    }

    return 0;
}
