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
    int n, k, q;
    cin >> n >> k >> q;
    int nn = 2e5 + 5;

    vi n_arr(nn);
    int l, r;
    rep(i, 0, n) {
        cin >> l >> r;
        n_arr[r+1]--;
        n_arr[l]++;
    }

    rep(i, 1, nn) {
        n_arr[i] += n_arr[i-1];
    }

    rep(i, 1, nn) {
        if (n_arr[i] >= k) n_arr[i] = 1;
        else n_arr[i] = 0;
        n_arr[i] += n_arr[i-1];
    }

    rep(i, 0, q) {
        cin >> l >> r;
        cout << (n_arr[r] - n_arr[l-1]) << "\n";
    }

    return 0;
}

