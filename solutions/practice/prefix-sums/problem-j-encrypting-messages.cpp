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
    int n, m, c;
    cin >> n >> m >> c;
    vlli a(n, 0);
    vlli b(m, 0);
    vlli s_a(n+2, 0);
    int steps = n-m+1;
    int l=0,r=0;
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    rep(i, 0, m) {
        l = i;
        r = min(i+steps, n);
        s_a[l] += b[i];
        s_a[r] -= b[i];
    }
    // for (auto &x: s_a) cout << x << " ";cout << "\n";
    rep(i, 1, n+1) {
        s_a[i] += s_a[i-1];
    }
    // for (auto &x: s_a) cout << x << " ";cout << "\n";

    rep(i, 0, n) {
        a[i] = (a[i]+s_a[i]) % c;
    }

    for (auto &x: a) cout << x << " ";cout << "\n";

    return 0;
}

