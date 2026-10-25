#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y,z) for (int x = y; x >= z; x--)
#define ll long long
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        int high = log2(n-1);
        int start = 1 << high;

        rep(i, 1, start) cout << i << " ";
        cout << "0 ";
        rep(j, start, n) cout << j << " ";
        cout << "\n";
    }

    return 0;
}

