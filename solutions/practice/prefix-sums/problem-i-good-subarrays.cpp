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
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vlli v(n, 0);
        vlli sum(n+1, 0);
        string s;
        cin >> s;
        map<int, int> mp;
        mp[0]++;
        // cout << s << "\n";
        // for (auto &x: v) cin >> x;
        rep(i, 0, n) {
            v[i] = s[i] - '0';
            sum[i+1] = (sum[i] + v[i])-1;
            // cout << v[i] << " ";
        }
        // cout << "\n";
        // for (auto &x: sum) cout << 

        lli ans=0;
        rep(i, 0, n) {
            ans += mp[sum[i+1]];
            mp[sum[i+1]]++;
        }
        cout << ans << "\n";
    }

    return 0;
}

