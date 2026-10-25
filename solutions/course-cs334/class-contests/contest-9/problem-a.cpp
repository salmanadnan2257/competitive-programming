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
    int _;
    // _ = 1; 
    cin >> _;
    while (_--) {
        int n, q;
        cin >> n >> q;
        vlli a(n, 0), sm(n+1, 0);
        for (auto &x: a) cin >> x;

        rep(i, 0, n) {
            sm[i+1] = sm[i] + a[i];
        }

        rep(i, 0, q) {
            int x, y;
            cin >> x >> y;
            
        }
    }

    return 0;
}

