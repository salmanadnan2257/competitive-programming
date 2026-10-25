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

/* --------------- RANDOM HELPER --------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random_in_range(ll l,ll r){
    uniform_int_distribution<ll> dist(l,r);
    return dist(rng);
}

// Dynamic Range Minimum Queries

/* --------------- 16) SOLVE --------------- */
struct SegmentTree{
    ll n; vll tree;
    SegmentTree(ll s):n(s),tree(4*s,INF){}
    SegmentTree(const vll& a):n(a.size()),tree(4*n,INF){ build(a,1,0,n-1); }

    void build(const vll& a, ll i, ll l, ll r){
        if(l==r){ tree[i]=(l<a.size()?a[l]:INF); return; }
        ll m=(l+r)/2;
        build(a,i*2,l,m);
        build(a,i*2+1,m+1,r);
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }

    void update_internal(ll i, ll l, ll r, ll pos, ll val){
        if(l==r){ tree[i]=val; return; }
        ll m=(l+r)/2;
        if(pos<=m) update_internal(i*2,l,m,pos,val);
        else update_internal(i*2+1,m+1,r,pos,val);
        tree[i]=min(tree[i*2],tree[i*2+1]);
    }

    ll query_internal(ll i, ll l, ll r, ll ql, ll qr){
        if(ql>r||qr<l) return INF;
        if(ql<=l&&r<=qr) return tree[i];
        ll m=(l+r)/2;
        return min(query_internal(i*2,l,m,ql,qr),query_internal(i*2+1,m+1,r,ql,qr));
    }

    void update(ll pos, ll val){
        if(pos<0||pos>=n) return;
        update_internal(1,0,n-1,pos,val);
    }

    ll query(ll ql, ll qr){
        if(ql<0||qr>=n||ql>qr) return INF;
        return query_internal(1,0,n-1,ql,qr);
    }
};

void solve(){
    ll N, Q; re(N, Q); vll arr(N);
    SegmentTree seg_tree(N);
    rep(i, 0, N) {
        ll x; re(x);
        arr[i] = x;
        seg_tree.update(i, x);
    }

    rep(i, 0, Q) {
        ll type, a, b; re(type, a, b); --a;
        if (type == 1) {
            seg_tree.update(a, b);
        } else {
            --b;
            ps(seg_tree.query(a, b));
        }
    }
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
