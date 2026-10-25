#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define sz(x) (ll)((x).size())
#define eb(x) emplace_back(x)
#define rep(x, y, z) for (ll x = (y); (x) < (z); (x)++)

class Solution {
public:
    long long appealSum(string s) {
        map<char, ll> cnt;
        map<char, vll> ind;
        ll si = sz(s);
        rep(i, 0, si) {
            char ch = s[i];
            ++cnt[ch];
            if (cnt[ch] == 1) ind[ch].eb(-1);
            ind[ch].eb(i);
        }
        ll ini = (si * (si+1)) / 2;
        ll ans = 0;
        for (auto &[a, b]: ind) {
            ind[a].eb(si);
            ll si2 = sz(b);
            ll tmp=0;
            rep(i, 0, si2-1) {
                ll nm = b[i];
                ll nm2 = b[i+1];
                ll diff = nm2-nm;
                if (nm == nm2 || b[i]+1 == b[i+1]) continue;
                tmp += ((diff * (diff-1)) / 2);
            }
            ans += (ini - tmp);
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    Solution ans;
    ll result = ans.appealSum(s);
    cout << result << "\n";
}
