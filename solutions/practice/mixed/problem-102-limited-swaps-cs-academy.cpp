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
vll a;
vector<pair<pll, ll>> t;
ll N, K;

void combine(ll v) {
    t[v].fi = max(t[v * 2].fi, t[v * 2 + 1].fi);
    t[v].se = t[v * 2].se + t[v * 2 + 1].se;
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = {{a[tl], -tl}, 1};
    } else {
        ll tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        combine(v);
    }
}

void update(ll v, ll tl, ll tr, ll pos) {
    if (tl == tr) {
        t[v] = {{-1, 0}, 0};
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos);
        }
        combine(v);
    }
}

pll query_max(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
        return {-1, 0};
    }
    if (l == tl && r == tr) {
        return t[v].fi;
    }
    ll tm = (tl + tr) / 2;
    pll l_res = query_max(v * 2, tl , tm, l, min(r, tm));
    pll r_res = query_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return max(l_res, r_res);
}

ll query_count(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return t[v].se;
    }
    ll tm = (tl + tr) / 2;
    ll st = query_count(v * 2, tl, tm, l, min(r, tm));
    ll en = query_count(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return st + en;
}

ll find_kth(ll v, ll tl, ll tr, ll k) {
    if (tl == tr) {
        return tl;
    }
    ll tm = (tl + tr) / 2;
    if (k <= t[v*2].se) {
        return find_kth(v * 2, tl, tm, k);
    } else {
        return find_kth(v * 2 + 1, tm + 1, tr, k - t[v * 2].se);
    }
}

void solve(){
    re(N, K); a.resize(N); re(a);
    t.assign(4 * N, {{0, 0}, 0});
    build(1, 0, N-1);

    vll res;
    rep(i, 0, N) {
        ll rem = N - i;
        ll lim = min(K + 1, rem);

        ll pos = find_kth(1, 0, N-1, lim);

        pll best = query_max(1, 0, N-1, 0, pos);
        ll val = best.fi;
        ll idx = -best.se;

        res.eb(val);
        ll swaps = query_count(1, 0, N - 1, 0, idx - 1);
        K -= swaps;

        update(1, 0, N - 1, idx);
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
