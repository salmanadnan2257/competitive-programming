// --------- Co-growing Sequence ---------

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
    _ = 1;
    // cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vi x(n), y(n);
        for (auto &a: x) cin >> a;

        int flag = 0;
        rep(i, 0, n) {
            flag = flag | x[i];
            y[i] = flag ^ x[i];
        }

        for (auto &a: y) {
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}
