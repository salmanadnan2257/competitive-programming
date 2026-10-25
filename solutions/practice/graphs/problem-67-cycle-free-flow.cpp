// --------- Cycle Free Flow ---------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define rep(x,y,z) for(ll x=y;x<z;(x)++)

ll n, m, q;
ll mxe;
vll depth;
vector<vector<pair<ll, ll>>> adj;
vvll up;
vvll minEdge;

void dfs(ll curr, ll par, ll d = 0, ll edgeWeight = LLONG_MAX) {
    up[curr][0] = par;
    minEdge[curr][0] = edgeWeight;
    depth[curr] = d;
    
    for (auto& [node, weight] : adj[curr]) {
        if (node != par) {
            dfs(node, curr, d + 1, weight);
        }
    }
}

ll minEdgeWeight(ll a, ll b) {
    ll minWeight = LLONG_MAX;

    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    
    // Calculate the depth difference
    ll diff = depth[b] - depth[a];

    for (ll i = mxe - 1; i >= 0; --i) {
        if ((diff >> i) & 1) {
            minWeight = min(minWeight, minEdge[b][i]);
            b = up[b][i];
        }
    }

    if (a == b) {
        return minWeight;
    }

    for (ll i = mxe - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            minWeight = min(minWeight, minEdge[a][i]);
            minWeight = min(minWeight, minEdge[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }

    minWeight = min(minWeight, minEdge[a][0]);
    minWeight = min(minWeight, minEdge[b][0]);
    
    return minWeight;
}


void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    mxe = (ll)log2(n) + 5;
    depth.resize(n, 0);
    adj.resize(n);
    up.assign(n, vll(mxe, -2));
    minEdge.assign(n, vll(mxe, LLONG_MAX));

    rep(i, 0, m) {
        ll x, y, c; cin >> x >> y >> c; --x; --y;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    dfs(0, -2);

    rep(l, 1, mxe) {
        rep(node, 0, n) {
            if (up[node][l-1] != -2) {
                up[node][l] = up[up[node][l-1]][l-1];
                minEdge[node][l] = min(minEdge[node][l-1], minEdge[up[node][l-1]][l-1]);
            }
        }
    }

    cin >> q;
    rep(i, 0, q) {
        ll x, y; cin >> x >> y; --x; --y;
        cout << minEdgeWeight(x, y) << "\n"; 
    }
}

int main() {
    solve();
    return 0;
}
