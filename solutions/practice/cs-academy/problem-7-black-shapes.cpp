/* ---------------- Competitive Programming Template for ICPC and Other Competitions ---------------- */

#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

/* ------------------- FAST I/O ------------------- */
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr)

/* ------------------- TYPE ALIASES ------------------- */
using ll = long long;
using lld = long double;
using vll = vector<ll>;
using vlld = vector<lld>;
using vb = vector<bool>;
using vvll = vector<vector<ll>>;
using vvlld = vector<vector<lld>>;
using pll = pair<ll, ll>;
using plld = pair<lld, lld>;

/* ------------------- MACROS ------------------- */
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((ll)(x).size())
#define nl "\n"

/* ------------------- CONSTANTS ------------------- */
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/* --------------- GCD and LCM --------------- */
inline ll gcd(ll a,ll b){ return b ? gcd(b,a%b) : a; }
inline ll lcm(ll a,ll b){ return (a/gcd(a,b))*b; }

/* --------------- FASTER INPUT/OUTPUT --------------- */
namespace __input {
    template<class T> void re(T &x){ cin >> x; }
    void re(lld &x){ string t; cin >> t; x=stold(t); }
    template<class T1,class T2> void re(pair<T1,T2> &p){ re(p.first,p.second); }
    template<class T> void re(vector<T> &a){ for(auto &x:a) re(x); }
    template<class T, size_t SZ> void re(array<T,SZ> &a){ for(auto &x:a) re(x); }
    template<class Arg,class...Args> void re(Arg &f,Args &...r){ re(f); re(r...); }
}
using namespace __input;

namespace __output {
    template<class T> void pr(const T &x){ cout<<x; }
    template<class T1,class T2> void pr(const pair<T1,T2> &p){ pr(p.first);pr(" ");pr(p.second); }
    template<class Arg,class...Args> void pr(const Arg &f,const Args &...r){ pr(f);pr(" ");pr(r...); }
    template<class T> void pr(const vector<T> &x){ for(const auto &a:x){ pr(a); pr(" "); } }
    void ps(){ pr("\n"); }
    template<class Arg> void ps(const Arg &f){ pr(f); ps(); }
    template<class Arg,class...Args> void ps(const Arg &f,const Args &...r){ pr(f); pr(" "); ps(r...); }
}
using namespace __output;

/* --------------- CONDITIONAL DEBUG PRIMITIVES --------------- */
#if defined(LOCAL) && LOCAL == SALMAN
    // SALMAN build: enable debug printing
    #define debug_pr(...) pr(__VA_ARGS__)   // print without newline
    #define debug_ps(...) ps(__VA_ARGS__)   // print with newline
#else
    // non-SALMAN build: disable debug printing
    #define debug_pr(...)      /* no-op */
    #define debug_ps(...)      /* no-op */
#endif

/* --------------- RANDOM HELPER --------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random_in_range(ll l,ll r){
    uniform_int_distribution<ll> dist(l,r);
    return dist(rng);
}

/* --------------- SOLVE --------------- */
ll N, M;
vvll a;
vector<vb> vis;
vll compSize;
vector<vector<ll>> compId;
ll dx[4] = {0, 0, 1,-1};
ll dy[4] = {1,-1, 0, 0};

bool valid(ll x, ll y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

ll dfs(ll x, ll y, ll id) {
    vis[x][y] = 1;
    compId[x][y] = id;
    ll cnt = 1;
    rep(i,0,4) {
        ll nx = x+dx[i], ny = y+dy[i];
        if (valid(nx,ny) && !vis[nx][ny] && a[nx][ny] == 1)
            cnt += dfs(nx,ny,id);
    }
    return cnt;
}

void solve(){
    re(N, M);
    a.assign(N, vll(M));
    vis.assign(N, vb(M,0));
    compId.assign(N, vector<ll>(M, -1));
    rep(i,0,N) re(a[i]);

    ll id = 0;
    compSize.clear();

    rep(i,0,N) {
        rep(j,0,M) {
            if (a[i][j] == 1 && !vis[i][j]) {
                ll sz = dfs(i,j,id);
                compSize.push_back(sz);
                id++;
            }
        }
    }

    ll res = 0;
    for (auto &v : compSize) res = max(res, v);

    rep(i,0,N) {
        rep(j,0,M) {
            if (a[i][j] == 0) {
                set<ll> st;
                rep(k,0,4) {
                    ll nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx,ny) && a[nx][ny] == 1) {
                        st.insert(compId[nx][ny]);
                    }
                }
                ll cur = 1;
                for (auto &c : st) cur += compSize[c];
                res = max(res, cur);
            }
        }
    }

    ps(res);
}

/* --------------- MAIN --------------- */
int main(){
    fast_io;

    #if defined(LOCAL) && LOCAL == SALMAN
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    #endif


    // // Precomputations Needed for Your Code
    // precompute_factorials();   // ✅ Required for nCr(n, r)
    // sieve(MAXN);               // ✅ Required for prime-related functions
    // compute_totient();         // ✅ Required for φ(n) calculations
    // compute_mobius();          // ✅ Required for Möbius function calculations

    cout << setprecision(12) << fixed;

    ll T=1;
    // cin >> T;
    while(T--) solve();


    #if defined(LOCAL) && LOCAL == SALMAN
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> duration = end - start;

    // Output duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
    #endif

    return 0;
}
