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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, c;
    cin >> n >> q >> c;
    // cnt[p][x][y]: how many stars with initial brightness p lie in the rectangle (1,1)..(x,y)
    vector<vector<vi>> cnt(c+1, vector<vi>(102, vi(102, 0)));
    int x, y, s;
    rep(i, 0, n) {
        cin >> x >> y >> s;
        cnt[s][x][y] += 1;
    }
    rep(p, 0, c+1) {
        rep(i, 1, 101) {
            rep(j, 1, 101) {
                cnt[p][i][j] += cnt[p][i-1][j] + cnt[p][i][j-1] - cnt[p][i-1][j-1];
            }
        }
    }
    int t, x1, y1, x2, y2;
    rep(i, 0, q) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll total = 0;
        rep(p, 0, c+1) {
            int k = cnt[p][x2][y2] - cnt[p][x1-1][y2] - cnt[p][x2][y1-1] + cnt[p][x1-1][y1-1];
            // a star that starts at p shines (p + t) mod (c + 1) at time t
            total += (ll)k * ((p + t) % (c + 1));
        }
        cout << total << "\n";
    }
    return 0;
}


