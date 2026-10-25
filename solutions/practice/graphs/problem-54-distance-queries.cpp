// --------- Distance Queries ---------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define eb(x) emplace_back(x)
#define pb(x) push_back(x)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define rep(x,y,z) for(ll x=y;x<z;(x)++)
#define per(x,y,z) for(ll x=y;x>=z;(x)--)
#define nl "\n"

// Solve
ll n = 2e5+100, q;
ll mxe = (ll)log2(n)+5;
vll depth(n, 0);
vvll adj(n, vll());
vvll up(n, vll(mxe, -2));

void dfs(ll curr, ll par, ll d=0) {
    up[curr][0] = par;
    depth[curr] = d;
    for (ll node: adj[curr]) if (node != par) dfs(node, curr, d+1);
}

ll lift(ll curr, ll dis) {
    rep(i, 0, mxe) {
        if (curr != -2 && (dis & (1 << i))) {
            curr = up[curr][i];
        }
    }

    return curr;
}

ll lca(ll a, ll b) {
    if (depth[a] > depth[b]) {
        a = lift(a, depth[a]-depth[b]);
    } else {
        b = lift(b, depth[b] - depth[a]);
    }

    if (a == b) return a;

    per(l, mxe-1, 0) {
        if (up[a][l] != up[b][l]) {
            a = up[a][l];
            b = up[b][l];
        }
    }

    return up[a][0];
}

ll dis(ll a, ll b) {
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    rep(i, 1, n) {
        ll x, y; cin >> x >> y; --x; --y;
        adj[x].eb(y);
        adj[y].eb(x);
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
        ll x, y; cin >> x >> y; --x; --y;
        cout << dis(x, y) << nl;
    }
}

int main() {
    ll T=1;
    while (T--) solve();
    return 0;
}
