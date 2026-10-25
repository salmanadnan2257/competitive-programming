#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define eb(x) emplace_back(x)
#define pb(x) push_back(x)
#define sz(x) (ll)(x.size())
#define rep(x,y,z) for (ll x=y;x<z;(x)++)
#define per(x,y,z) for (ll x=z;x>=y;(x)--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define nl "\n"

ll n = 2e5+100, q;
ll mxe = (ll)log2(n)+5;
vvll adj(n, vll());
vvll up(n, vll(mxe, -2));

void dfs(ll curr, ll par) {
    up[curr][0] = par;
    for (ll node: adj[curr]) dfs(node, curr);
}

void solve() {
    cin >> n >> q;
    rep(i, 1, n) {
        ll x; cin >> x; --x;
        adj[x].eb(i);
    }

    dfs(0, -2);
    rep(l, 1, mxe) {
        rep(node, 0, n) {
            if (up[node][l-1] != -2) {
                up[node][l] = up[up[node][l-1]][l-1];
            }
        }
    }

    rep(i, 0, q) {
        ll node, k; cin >> node >> k; --node;
        rep(l, 0, mxe) {
            if (node != -2 && (k & (1 << l))) {
                node = up[node][l];
            }
        }
        cout << node+1 << nl;
    }
}

int main() {
    ll T = 1;
    while (T--) solve();
    return 0;
}
