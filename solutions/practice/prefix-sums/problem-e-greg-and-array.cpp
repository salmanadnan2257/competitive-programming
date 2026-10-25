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
    ll int n, m, k;
    cin >> n >> m >> k;
    ll int nn = 1e5 + 5;

    vlli n_arr(n, 0);
    for (auto &x: n_arr) cin >> x;
    // cout << "First\n";

    vlli ops((3 * m)+100, 0);
    ll int l, r, d;
    rep(i, 0, m) {
        cin >> l >> r >> d;
        // ops.eb(l);ops.eb(r);ops.eb(d); // (i+(2*i))
        ll int ind = 3 * i;
        ops[ind] = l;
        ops[ind+1] = r;
        ops[ind+2] = d;
    }
    // cout << "Second\n";

    vlli que(m+2, 0);
    // for (auto &x: que) cout << x << " ";
    // cout << "\n";
    rep(i, 0, k) {
        // cout << i << " ";
        cin >> l >> r;
        // cout << l << " ";
        // cout << r << "\n";
        que[r+1] -= 1;
        // cout << "Mid1\n";
        que[l] += 1;
        // cout << "Mid2\n";
    }
    // cout << "Third\n";
    // for (auto &x: que) cout << x << " ";cout << "\n";
    rep(i, 1, m+2) {
        que[i] += que[i-1];
    }
    // cout << "Fourth\n";
    // for (auto &x: que) cout << x << " ";cout << "\n";

    vlli n_add(n+2, 0);
    rep(i, 0, m) {
        // l = ops[i]
        l = ops[3 * i];
        r = ops[3 * i + 1];
        d = ops[3 * i + 2];
        ll int num = d * que[i+1];
        // cout << l << " " << r << " " << d << " " << num << "\n";
        n_add[r+1] -= num;
        n_add[l] += num;
    }
    // cout << "Fifth\n";
    // for (auto &x: n_add) cout << x << " "; cout << "\n";
    rep(i, 1, n+2) {
        n_add[i] += n_add[i-1];
    }
    // for (auto &x: n_add) cout << x << " "; cout << "\n";
    // cout << "Sixth\n";

    rep(i, 0, n) {
        n_arr[i] = n_arr[i] + n_add[i+1];
    }
    // cout << "Seventh\n";

    for (auto &x: n_arr) cout << x << " ";
    cout << "\n";

    return 0;
}


