#include <bits/stdc++.h>

int main() {
#ifdef LOCAL
freopen("../IO/c.in", "r", stdin);
//  freopen("../IO/c.out", "w", stdout);
#else
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);
#endif
int n;
std::cin >> n;
std::vector<std::vector<int>> adj(n);
for (int i = 0, u, v; i < n - 1; ++i) {
    std::cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
std::vector<int> sz(n, 0);
std::function<int(int, int)> dfs1 = [&](int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
    if (v != p) {
        sz[u] += dfs1(v, u);
    }
    }
    return sz[u];
};
dfs1(0, -1);
std::vector<int> can(n, 0);
std::function<void(int, int)> dfs2 = [&](int u, int p) {
    std::vector<int> can1(n + 1, 0);
    can1[0] = 1;
    for (int v : adj[u]) {
    for (int w = n - 1 - sz[v]; w >= 0; --w) {
        can1[w + sz[v]] |= can1[w];
    }
    }
    for (int i = 1; i < n - 1; ++i) {
    can[i] |= can1[i];
    }
    for (int v : adj[u]) {
    if (v == p) continue;
    sz[u] -= sz[v];
    sz[v] += sz[u];
    dfs2(v, u);
    sz[v] -= sz[u];
    sz[u] += sz[v];
    }
};
dfs2(0, -1);
std::cout << std::accumulate(can.begin(), can.end(), 0) << '\n';
for (int i = 1; i < n - 1; ++i) {
    if (can[i]) {
    std::cout << i << ' ' << n - 1 - i << '\n';
    }
}
return 0;
}
