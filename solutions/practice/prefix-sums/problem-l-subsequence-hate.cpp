// --------- Subsequence Hate ---------

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
        string s;
        cin >> s;
        
        size_t n = s.size();
        int count_1 = 0;
        int count_0 = 0;

        rep(i, 0, n) {
            if (s[i] == '1') {
                count_1++;
            } else {
                count_0++;
            }
        }

        vi pref_0(n+1, 0);
        vi pref_1(n+1, 0);

        if (s[0] == '0') {
            pref_0[0] = 1;
            pref_1[0] = 0;
        } else {
            pref_0[0] = 0;
            pref_1[0] = 1;
        }

        rep(i, 1, n) {
            if (s[i] == '0') {
                pref_0[i] = pref_0[i-1] + 1;
                pref_1[i] = pref_1[i-1];
            } else {
                pref_0[i] = pref_0[i-1];
                pref_1[i] = pref_1[i-1] + 1;
            }
        }
        
        // for (auto &x: pref_0) cout << x << " ";cout << "\n";
        // for (auto &x: pref_1) cout << x << " ";cout << "\n";

        int ans = n+1;
        rep(i, 0, n) {
            ans = min(ans, pref_1[i] + (count_0 - pref_0[i]));
        }

        rep(i, 0, n) {
            ans = min(ans, pref_0[i] + (count_1 - pref_1[i]));
        }

        cout << ans << "\n";
    }

    return 0;
}

