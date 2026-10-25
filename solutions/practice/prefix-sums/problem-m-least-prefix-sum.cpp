// --------- Least Prefix Sum ---------

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
        int n, m;
        cin >> n >> m;
        m--;

        vll a(n), prf_sm(n, 0);

        for (ll i=0; i<n; i++) cin >> a[i];
        prf_sm[0] = a[0];
        for (ll i=1; i<n; i++) {
            prf_sm[i] = prf_sm[i-1] + a[i];
        }

        ll curr=prf_sm[m], ans=0;
        // for (auto &x: prf_sm) cout << x << " ";cout << "\n";
        int count = 0;
        priority_queue<ll> max_heap;
        for (ll i=m; i>=0; i--) {
            // cout << "in" << prf_sm[i] << " " << curr << " " << a[i] << "\n";
            while (prf_sm[i] < curr) {
                count++;
                ll top = max_heap.top();
                // cout << prf_sm[i] << " " << curr << " " << top << "\n";
                max_heap.pop();
                curr -= 2*top;
                ans++;
                if (count >= 10) {break;}
            }
            max_heap.push(a[i]);
        }
        // cout << "out" << "\n";

        curr = prf_sm[m];
        priority_queue<ll, vector<ll>, greater<ll>> min_heap;
        for (ll i=m+1; i<n; i++) {
            // cout << "in2" << "\n";
            min_heap.push(a[i]);
            ll topp = min_heap.top();
            while (prf_sm[i] < curr) {
                ll top = min_heap.top();
                min_heap.pop();
                curr += 2*top;
                ans++;
            }
        }
        // cout << "in3" << "\n";

        cout << ans << "\n";
    }

    return 0;
}

/* 
6
4 3
-1 -2 -3 -4
4 3
1 2 3 4
1 1
1
5 5
-2 3 -5 1 -20
5 2
-2 3 -5 -5 -20
10 4
345875723 -48 384678321 -375635768 -35867853 -35863586 -358683842 -81725678 38576 -357865873
*/
