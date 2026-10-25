// --------- Misha, Grisha, and the Underground ---------

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

ll calc(ll f, ll s, ll t) {
    ll ans = 0;
    bool is1 = lca(f, s) == f, is2 = lca(f, t) == f;
    if (is1 != is2) return 1;

    if (is1)
        ans = max(ans, depth[lca(s, t)] - depth[f]);
    else if (lca(f, s) != lca(f, t))
        ans = max(ans, depth[f] - max(depth[lca(f, s)], depth[lca(f, t)]));
    else
        ans = max(ans, depth[f] + depth[lca(s, t)] - 2 * depth[lca(f, t)]);

    return ans + 1;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    rep(i, 1, n) {
        ll x; cin >> x; --x; adj[x].eb(i);
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
        ll a, b, c; cin >> a >> b >> c; --a, --b, --c;
        
        vll arr = {
            calc(a, b, c),
            calc(b, a, c),
            calc(c, a, b)
        };
        
        cout << *max_element(arr.begin(), arr.end()) << nl;
    }
}

int main() {
    ll T=1;
    while (T--) solve();
    return 0;
}