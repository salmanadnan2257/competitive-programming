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
const ll INF = 1e15;


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

/* --------------- RANDOM HELPER --------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random_in_range(ll l,ll r){
    uniform_int_distribution<ll> dist(l,r);
    return dist(rng);
}

// Wonderful City

/* --------------- SOLVE --------------- */
ll rows(const vvll &arr, vll cost) {
    ll n = sz(arr);
    vll dp1(n, 0), dp2(n, 0);
    dp1[0] = 0, dp2[0] = cost[0];
    rep(i, 1, n) {
        bool v1 = 0, v2 = 0, v3 = 0;
        rep(j, 0, n) {
            // TF prohibited
            if (arr[i][j] == arr[i-1][j] + 1) v1 = 1;
            // TT, FF prohibited
            if (arr[i][j] == arr[i-1][j]) v2 = 1;
            // FT is prohibited
            if (arr[i][j]+1 == arr[i-1][j]) v3 = 1;
        }

        if (v1 && v2 && v3) return INF;

        if (v1 && v2) {
            dp1[i] = INF;
            dp2[i] = dp1[i-1] + cost[i];
        } else if (v2 && v3) {
            dp1[i] = dp2[i-1];
            dp2[i] = INF;
        } else if (v1 && v3) {
            dp1[i] = dp1[i-1];
            dp2[i] = dp2[i-1] + cost[i];
        } else if (v1) {
            dp1[i] = dp1[i-1];
            dp2[i] = min(dp1[i-1], dp2[i-1]) + cost[i];
        } else if (v2) {
            dp1[i] = dp2[i-1];
            dp2[i] = dp1[i-1] + cost[i];
        } else if (v3) {
            dp1[i] = min(dp1[i-1], dp2[i-1]);
            dp2[i] = dp2[i-1] + cost[i];
        } else {
            dp1[i] = min(dp1[i-1], dp2[i-1]);
            dp2[i] = min(dp1[i-1], dp2[i-1]) + cost[i];
        }
    }

    return min(dp1[n-1], dp2[n-1]);
}

void transpose(vvll & arr) {
    ll N = sz(arr);
    rep(i, 0, N) rep(j, i+1, N) swap(arr[i][j], arr[j][i]);
}

void solve(){
    ll N; re(N); vvll arr(N, vll(N)); re(arr); vll cost_a(N), cost_b(N); re(cost_a, cost_b);
    ll ans = rows(arr, cost_a);
    if (ans == INF) {
        ps(-1); return;
    }
    transpose(arr);
    ans += rows(arr, cost_b);
    if (ans >= INF) {
        ps(-1); return;
    }
    ps(ans);
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
    cin >> T;
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
