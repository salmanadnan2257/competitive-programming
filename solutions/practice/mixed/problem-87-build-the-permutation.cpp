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

// Build the Permutation

/* --------------- SOLVE --------------- */
void solve(){
    ll N, A, B; re(N, A, B);
    if (A + B + 2 > N || abs(A - B) > 1) {
        ps(-1);
        return;
    }

    set<ll> st;
    vll arr(N, 0);
    rep(i, 1, N+1) st.insert(i);
    if (A == B) {
        for (ll i = 1; i < N; i += 2) {
            if (!B) break;
            --B;
            arr[i] = *st.begin();
            st.erase(st.begin());
        }
        for (ll &curr: arr) {
            if (!curr) {
                curr = *st.begin();
                st.erase(st.begin());
            }
        }
        if (A) swap(arr[N-2], arr[N-1]);
    } else if (A > B) {
        for (ll i = 1; i < N; i += 2) {
            if (!A) break;
            --A;
            arr[i] = *st.rbegin();
            st.erase(prev(st.end()));
        }
        for (ll &curr: arr) {
            if (!curr) {
                curr = *st.rbegin();
                st.erase(prev(st.end()));
            }
        }
    } else {
        for (ll i = 1; i < N; i += 2) {
            if (!B) break;
            --B;
            arr[i] = *st.begin();
            st.erase(st.begin());
        }
        for (ll &curr: arr) {
            if (!curr) {
                curr = *st.begin();
                st.erase(st.begin());
            }
        }
    }
    ps(arr);
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
