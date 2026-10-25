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
    ll int n, q, c;
    cin >> n >> q >> c;
    vlli x_sum(102, 0), y_sum(102, 0), x_count(102, 0), y_count(102, 0);

    int x, y, s;
    rep(i, 0, n) {
        cin >> x >> y >> s;
        x_sum[x] += s;
        y_sum[y] += s;
        x_count[x] += 1;
        y_count[y] += 1;
    }

    int t, x1, y1, x2, y2;
    int l_s = 0, l_c = 0, r_s = 0, r_c = 0;
    int temp = 0, temp_1 = 0;
    rep(i, 0, q) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        l_s = x_sum[x2] - x_sum[x1-1];
        l_c = x_count[x2] - x_count[x1-1];
        r_s = x_sum[y2] - y_count[y1-1];
        r_c = x_count[y2] - y_count[y1];

        if (l_c == r_c) {
            temp = l_s;
            temp_1 = l_s;
        } else if (l_c < r_c) {
            temp = l_s;
            temp_1 = l_c;
        } else {
            temp = r_s;
            temp_1 = r_c;
        }

        cout << (c - ((temp + (t * temp_1)) % c)) << "\n";
    }

    return 0;
}


