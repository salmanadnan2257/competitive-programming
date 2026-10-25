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
    int n;
    cin >> n;
    vi a(n);
    for (auto &x: a) cin >> x;

    int l=0, ans=0;
    map<int, int> freq;

    rep(i, 0, n) {
        freq[a[i]]++;
        while (freq.rbegin()->first - freq.begin()->first > 1) {
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }
        ans = max(ans, (i-l)+1);
    }

    // cout << curr << " " << ans << "\n";
    // ans = max(curr, ans);

    cout << ans << "\n";

    return 0;
}

