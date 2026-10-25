#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define ll long long
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

int main() {
    int _;
    cin >> _;

    while (_--) {
        int a, b;
        cin >> a >> b;
        cout << (a ^ b) << "\n";
    }

    return 0;
}
