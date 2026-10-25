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
using vb = vector<bool>;
using vvll = vector<vector<ll>>;
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

#ifdef LOCAL
    #define debug(x) cerr<<#x<<"="<<(x)<<endl
#else
    #define debug(x)
#endif

/* ------------------- CONSTANTS ------------------- */
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/* Forward Decaration of all the functions */
inline ll gcd(ll a, ll b); inline ll lcm(ll a, ll b); inline bool is_power_of_two(ll n); inline bool is_bit_set(ll n, ll k); inline ll set_bit(ll n, ll k); inline ll clear_bit(ll n, ll k); inline ll toggle_bit(ll n, ll k); inline ll count_set_bits(ll n); inline ll count_trailing_zeros(ll n); inline ll count_leading_zeros(ll n); inline ll total_bits(ll n); inline ll count_zero_bits(ll n); inline ll lowest_set_bit(ll n); inline ll lowest_set_bit_position(ll n); inline ll xor_from_1_to_n(ll n); inline ll reverse_bits(ll n); inline ll msb_index(ll n); inline ll msb_value(ll n); inline ll binpow(ll a, ll b); inline ll binpowmod(ll a, ll b, ll m); inline lld pow_using_log(lld a, lld n); inline ll mod_inv(ll a, ll m); inline ll ext_gcd(ll a, ll b, ll &x, ll &y); inline ll mod_inv_euclid(ll a, ll m); inline bool is_prime_simple(ll n); inline ll count_divisors(ll n); inline void sieve(ll n); inline vll prime_factors(ll n); inline ll stirling_factorial(ll n); inline ll factorial(ll n); inline ll compute_factorial(ll n); inline void build_lca(const vector<vll> &g, ll root); inline ll get_lca(ll a, ll b); inline vector<vll> mat_mul(const vector<vll> &A, const vector<vll> &B, ll mod); inline vector<vll> mat_pow(vector<vll> base, ll exp, ll mod); inline vll topo_sort(const vector<vll> &g); inline vll bfs(const vector<vll> &g, ll s); inline vll dfs(const vector<vll> &g, ll s); inline void compute_totient(); inline ll crt(vll a, vll m); inline ll mul(ll a, ll b); inline ll add(ll a, ll b); inline ll divide(ll a, ll b); inline void precompute_factorials(); inline ll ncr(ll n, ll r); inline ll ncr_normal(ll n, ll r); inline ll ncr_direct(ll n, ll r, ll mod); inline ll ncr_direct_without_mod(ll n, ll r); inline void compute_mobius(); inline void set_input_output(); inline void compare_output(); inline ll discrete_log_bsgs(ll a, ll b, ll m); inline ll random_in_range(ll l, ll r); inline void solve();

/* --------------- 1) SHORT HELPER FUNCTIONS --------------- */
inline ll gcd(ll a,ll b){ return b ? gcd(b,a%b) : a; }
inline ll lcm(ll a,ll b){ return (a/gcd(a,b))*b; }
inline bool is_power_of_two(ll n){ return (n>0 && !(n&(n-1))); }
inline bool is_bit_set(ll n,ll k){ return (n & (1LL<<k))!=0; }
inline ll set_bit(ll n,ll k){ return n | (1LL<<k); }
inline ll clear_bit(ll n,ll k){ return n & ~(1LL<<k); }
inline ll toggle_bit(ll n,ll k){ return n ^ (1LL<<k); }
inline ll count_set_bits(ll n){ return __builtin_popcountll(n); }
inline ll count_trailing_zeros(ll n){ return (n==0)?64:__builtin_ctzll(n); }
inline ll count_leading_zeros(ll n){ return (n==0)?64:__builtin_clzll(n); }
inline ll total_bits(ll n){ return 64 - count_leading_zeros(n); }
inline ll count_zero_bits(ll n){ return 64 - count_set_bits(n); }
inline ll lowest_set_bit(ll n){ return n & (-n); }
inline ll lowest_set_bit_position(ll n){ return (n==0)?0:__builtin_ffsll(n); }
inline ll xor_from_1_to_n(ll n){ return (n%4==0) ? n : ((n%4==1)?1:((n%4==2)?(n+1):0)); }
inline ll reverse_bits(ll n){ ll r=0; for(ll i=0;i<64;i++){ if(n&(1ULL<<i)) r|=(1ULL<<(63-i)); } return r; }
inline ll msb_index(ll n){return n?63LL-count_leading_zeros(n):-1;} 
inline ll msb_value(ll n){return n?1ULL<<(63LL-count_leading_zeros(n)):0LL;}

/* --------------- 2) NUMBER THEORY: BINPOW, MOD INV, ETC. --------------- */
/* Fast exponentiation (no modulus) */
inline ll binpow(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b & 1) ans*=a;
        a*=a; b>>=1;
    }
    return ans;
}
/* Fast exponentiation with modulus */
inline ll binpowmod(ll a,ll b,ll m){
    ll ans=1; a%=m;
    while(b>0){
        if(b & 1) ans=(ans*a)%m;
        a=(a*a)%m; b>>=1;
    }
    return ans;
}
/* Float-power for approximate real calculations */
inline lld pow_using_log(lld a,lld n){ return expl(n*logl(a)); }
/* Modular inverse using Fermat (mod prime) */
inline ll mod_inv(ll a,ll m){ return binpowmod(a,m-2,m); }
/* Extended Euclid for inverse if mod not prime */
inline ll ext_gcd(ll a,ll b,ll &x,ll &y){
    if(!b){ x=1; y=0; return a; }
    ll x1,y1; ll g=ext_gcd(b,a%b,x1,y1);
    x=y1; y=x1 - (a/b)*y1;
    return g;
}
inline ll mod_inv_euclid(ll a,ll m){
    ll x,y,g=ext_gcd(a,m,x,y);
    return (g==1? (x%m + m)%m : -1);
}
/* Simple primality check O(sqrt(n)) */
inline bool is_prime_simple(ll n){
    if(n<2)return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
/* Count divisors O(sqrt(n)) */
inline ll countDivisors(ll n){
    ll tot=1,c=0;
    while(n%2==0){ n/=2; c++; }
    tot*=(c+1);
    for(ll i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0){ n/=i; c++; }
        tot*=(c+1);
    }
    if(n>1) tot*=2;
    return tot;
}

/* --------------- 3) SIEVE OF ERATOSTHENES (LINEAR) --------------- */
static const ll MAXN = 1000000 + 5;
vector<bool> is_prime(MAXN+1,true);
vector<ll> primes, spf(MAXN+1);
inline void sieve(ll n){
    iota(spf.begin(),spf.end(),0);
    is_prime[0]=false; is_prime[1]=false;
    for(ll i=2;i<=n;i++){
        if(is_prime[i]){ primes.push_back(i); spf[i]=i; }
        for(ll p: primes){
            if(p*i>n || p>spf[i]) break;
            is_prime[p*i]=false;
            spf[p*i]=p;
        }
    }
}
/* Factorize using precomputed primes/spf */
inline vll prime_factors(ll n){
    vll f;
    for(ll p: primes){
        if(p*p>n) break;
        while(n%p==0){ f.push_back(p); n/=p; }
    }
    if(n>1) f.push_back(n);
    return f;
}

/* --------------- 4) FACTORIALS & STIRLING APPROX --------------- */
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#ifndef M_E
    #define M_E   2.71828182845904523536
#endif


inline ll stirling_factorial(ll n){
    if(n<2)return 1;
    long double nd=(long double)n;
    long double approx=sqrtl(2.0L*M_PI*nd)*powl(nd/M_E,nd);
    return (ll)llroundl(approx);
}
inline ll factorial(ll n){
    if(n<0) return 0;
    ll r=1; for(ll i=2;i<=n;i++){
        r*=i; if(r<0) return -1; /* overflow sign */
    }
    return r;
}
inline ll compute_factorial(ll n){ return (n<20)? factorial(n) : stirling_factorial(n); }

/* --------------- 5) DSU (DISJOINT SET UNION) --------------- */
struct DSU{
    vll parent, rank;
    DSU(ll n){ parent.resize(n); rank.resize(n,0); iota(all(parent),0); }
    ll find(ll v){ return (parent[v]==v ? v : parent[v]=find(parent[v])); }
    void unite(ll a,ll b){
        a=find(a); b=find(b);
        if(a!=b){
            if(rank[a]<rank[b]) swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
        }
    }
};

/* --------------- 6) SEGMENT TREE (LAZY PROP) --------------- */
struct SegmentTree{
    ll n; vll tree,lazy;
    SegmentTree(ll s):n(s),tree(4*s,0),lazy(4*s,0){}
    inline void apply(ll idx,ll l,ll r,ll val){
        tree[idx]+=val*(r-l+1);
        lazy[idx]+=val;
    }
    inline void push(ll idx,ll l,ll r){
        if(lazy[idx]){
            ll m=(l+r)/2;
            apply(idx*2,l,m,lazy[idx]);
            apply(idx*2+1,m+1,r,lazy[idx]);
            lazy[idx]=0;
        }
    }
    void update(ll idx,ll l,ll r,ll ql,ll qr,ll val){
        if(ql>r||qr<l)return;
        if(ql<=l&&r<=qr){ apply(idx,l,r,val); return; }
        push(idx,l,r);
        ll m=(l+r)/2;
        update(idx*2,l,m,ql,qr,val);
        update(idx*2+1,m+1,r,ql,qr,val);
        tree[idx]=tree[idx*2]+tree[idx*2+1];
    }
    ll query(ll idx,ll l,ll r,ll ql,ll qr){
        if(ql>r||qr<l) return 0;
        if(ql<=l&&r<=qr) return tree[idx];
        push(idx,l,r);
        ll m=(l+r)/2;
        return query(idx*2,l,m,ql,qr)+query(idx*2+1,m+1,r,ql,qr);
    }
};

/* --------------- 7) ADDITIONAL MATH: TOTIENT, CRT, ETC. --------------- */
static vll phi(MAXN);
inline void compute_totient(){
    iota(all(phi),0);
    for(ll i=2;i<MAXN;i++){
        if(phi[i]==i){
            for(ll j=i;j<MAXN;j+=i){
                phi[j]=phi[j]*(i-1)/i;
            }
        }
    }
}
/* CRT for pairwise-coprime moduli */
inline ll crt(vll a,vll m){
    ll prod=1,res=0; ll n=(ll)a.size();
    for(ll x:m) prod*=x;
    rep(i,0,n){
        ll p=prod/m[i];
        ll inv=mod_inv(p,m[i]); /* or mod_inv_euclid if not prime */
        res=(res+ a[i]*((inv%prod)* (p%prod) % prod))%prod;
    }
    return res;
}

/* --------------- 8) MODNUM STRUCT + PRECOMPUTED FACTORIALS FOR nCr --------------- */
template<ll M> struct modnum{
    ll v; modnum():v(0){} modnum(ll _v){ _v%=M; if(_v<0) _v+=M; v=_v;}
    modnum& operator+=(const modnum&o){ v+=o.v;if(v>=M)v-=M;return *this;}
    modnum& operator-=(const modnum&o){ v-=o.v;if(v<0)v+=M;return *this;}
    modnum& operator*=(const modnum&o){ v=(ll)((__int128)v*o.v%M);return *this;}
    modnum& operator/=(const modnum&o){ return *this *= o.inv();}
    modnum pow(ll e)const{
        modnum r=1,b=*this;while(e>0){ if(e&1)r*=b; b*=b; e>>=1;}return r;
    }
    modnum inv()const{ return pow(M-2);} /* for prime M */
};
using mn = modnum<1000000007>; 

ll mul(ll a, ll b) {
    return (((a % MOD) * (b % MOD)) % MOD);
}

ll add(ll a, ll b) {
    return ( (a % MOD) + (b % MOD) + MOD ) % MOD;
    /* a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a; */
}

ll divide(ll a, ll b) {
	return mul(a, mod_inv(b, MOD));
}

static vector<ll> fact_arr(MAXN), i_fact_arr(MAXN);
inline void precompute_factorials(){
    fact_arr[0]=i_fact_arr[0]=1;
    for(ll i=1;i<MAXN;i++){
        fact_arr[i]=( (fact_arr[i-1]%MOD) * (i%MOD) )%MOD;
    }
    /* invert factorial of (MAXN-1) */
    mn finv = fact_arr[MAXN-1];
    finv=finv.inv(); /* modular inverse */
    i_fact_arr[MAXN-1]=finv.v;
    for(ll i=MAXN-2;i>=1;i--){
        i_fact_arr[i]=( (i_fact_arr[i+1]%MOD)*((i+1)%MOD) )%MOD;
    }
}
inline ll ncr(ll n,ll r){
    if(r>n||r<0) return 0;
    ll ans=( (fact_arr[n]%MOD) * (i_fact_arr[r]%MOD) )%MOD;
    ans=( ans * (i_fact_arr[n-r]%MOD) )%MOD;
    return ans;
}
inline ll ncr_normal(ll n, ll r) {
    return divide(fact_arr[n], mul(fact_arr[r], fact_arr[n-r]));
}
inline ll ncr_direct(ll n, ll r, ll mod=MOD) {
    if (r > n || r < 0) return 0;
    ll res = 1;
    for (ll i = 0; i < r; ++i) {
        res = (res * (n - i)) % mod;
        res = (res * mod_inv(i + 1, mod)) % mod;
    }
    return res;
}
inline ll ncr_direct_without_mod(ll n, ll r) {
    ll res = 1 ;
    for(int i = 1 ; i<=r;i++){
        res = (res * (n-i+1) / i);
    }
    return res;
}


/* --------------- 9) MOBIUS FUNCTION --------------- */
static vector<ll> mobius(MAXN,1);
inline void compute_mobius(){
    vector<bool> primeMark(MAXN,true);
    primeMark[0]=false; primeMark[1]=false;
    for(ll i=2;i<MAXN;i++){
        if(primeMark[i]){
            for(ll j=i;j<MAXN;j+=i){
                primeMark[j]=false; mobius[j]*=-1;
            }
            long long sq=(long long)i*i;
            for(long long j=sq;j<MAXN;j+=sq) mobius[j]=0;
        }
    }
}

/* --------------- 10) FENWICK TREE (Binary Indexed Tree) --------------- */
struct Fenwick{
    ll n; vll fenw;
    Fenwick(ll _n):n(_n),fenw(_n+1,0){}
    inline void update(ll i,ll d){ for(;i<=n;i+=(i&-i)) fenw[i]+=d; }
    inline ll query(ll i){ ll s=0; for(;i>0;i-=(i&-i)) s+=fenw[i]; return s; }
    inline ll rangeQuery(ll l,ll r){ return (l>r?0: query(r)-query(l-1)); }
};

/* --------------- 11) GRAPH ALGORITHMS: BFS, DFS, TOPO SORT, LCA, ETC. --------------- */

/* BFS returning distance array from start node */
inline vll bfs(const vector<vll> &g,ll s){
    vll d(g.size(),-1); queue<ll>q; q.push(s); d[s]=0;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll v: g[u]) if(d[v]<0){ d[v]=d[u]+1; q.push(v); }
    }
    return d;
}

/* DFS iterative: returns order of visitation */
inline vll dfs(const vector<vll> &g,ll s){
    vll vis(g.size(),0),order; stack<ll>st; st.push(s);
    while(!st.empty()){
        ll u=st.top(); st.pop();
        if(!vis[u]){
            vis[u]=1; order.pb(u);
            for(auto it=g[u].rbegin();it!=g[u].rend();++it){
                ll x=*it; if(!vis[x]) st.push(x);
            }
        }
    }
    return order;
}

/* Topological Sort (Kahn’s Algo) for DAG */
inline vll topo_sort(const vector<vll> &g){
    ll n=(ll)g.size(); vll ind(n,0),res;
    for(auto &adj:g) for(ll v:adj) ind[v]++;
    queue<ll>q; rep(i,0,n) if(ind[i]==0) q.push(i);
    while(!q.empty()){
        ll u=q.front(); q.pop(); res.pb(u);
        for(ll v:g[u]) if(--ind[v]==0) q.push(v);
    }
    return (sz(res)==n ? res : vll());
}

/* LCA with binary-lifting: build in O(n log n), query O(log n) */
static const ll LOG=20;
vll depth;
vector<vll> up;
inline void build_lca(const vector<vll> &g,ll root=0){
    ll n=(ll)g.size(); depth.assign(n,0); up.assign(n,vll(LOG,-1));
    queue<ll>q; q.push(root); vll vis(n,0); vis[root]=1; up[root][0]=root;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll w:g[u]) if(!vis[w]){
            vis[w]=1; depth[w]=depth[u]+1; up[w][0]=u; q.push(w);
        }
    }
    rep(k,1,LOG) rep(v,0,n) up[v][k]=up[ up[v][k-1] ][k-1];
}
inline ll get_lca(ll a,ll b){
    if(depth[a]<depth[b]) swap(a,b);
    ll diff=depth[a]-depth[b];
    rep(k,0,LOG) if(diff&(1LL<<k)) a=up[a][k];
    if(a==b) return a;
    per(k,LOG-1,0){
        if(up[a][k]!=up[b][k]){a=up[a][k];b=up[b][k];}
    }
    return up[a][0];
}

/* --------------- 12) DISCRETE LOG (Baby-step Giant-step) --------------- */
inline ll discrete_log_bsgs(ll a,ll b,ll m){
    a%=m; b%=m; if(b==1)return 0;
    ll n=(ll)ceill(sqrtl((long double)m)), an=1;
    unordered_map<ll,ll> vals;
    /* store a^(i+1) */
    rep(i,0,n){ an=(an*a)%m; vals[an]=i+1; }
    /* base ~ a^(-n) */
    ll base = binpowmod(a,m-n-1,m);
    ll cur=b;
    rep(j,0,n){
        if(vals[cur]) return j*n + (vals[cur]-1);
        cur=(cur*base)%m;
    }
    return -1;
}

/* --------------- 13) MATRIX EXPONENTIATION --------------- */
inline vector<vll> math_mul(const vector<vll> &A,const vector<vll> &B,ll mod){
    ll n=(ll)A.size(), m=(ll)B[0].size(), p=(ll)B.size();
    vector<vll> R(n,vll(m,0));
    rep(i,0,n) rep(j,0,m) rep(k,0,p) R[i][j]=(R[i][j] + A[i][k]*B[k][j])%mod;
    return R;
}
inline vector<vll> math_pow(vector<vll> base,ll exp,ll mod){
    ll n=(ll)base.size();
    vector<vll>res(n,vll(n,0)); 
    rep(i,0,n) res[i][i]=1;
    while(exp>0){
        if(exp & 1) res=math_mul(res,base,mod);
        base=math_mul(base,base,mod);
        exp>>=1;
    }
    return res;
}

/* --------------- 14) LOCAL I/O + COMPARE OUTPUT --------------- */
inline void set_input_output(){
    #ifdef LOCAL
        ifstream fin("input.txt"), fout("output.txt");
        if(fin && fout){
            freopen("input.txt","r",stdin);
            freopen("temp_output.txt","w",stdout);
        }
    #endif
}
inline void compare_output(){
    #ifdef LOCAL
        ifstream ex("output.txt"), ac("temp_output.txt");
        cout<<"Running input.txt\n\n"<<"Expected Output:\n";
        vector<string> e,a; string ln;
        while(getline(ex,ln)){ while(!ln.empty() && isspace(ln.back())) ln.pop_back(); e.push_back(ln); cout<<ln<<"\n"; }
        cout<<"\nOutput:\n";
        while(getline(ac,ln)){ while(!ln.empty() && isspace(ln.back())) ln.pop_back(); a.push_back(ln); cout<<ln<<"\n"; }
        cout<<"\nAre they same?\n"<<( (e==a)?"Yes":"No" )<<"\n";
    #endif
}

/* --------------- 15) FASTER INPUT/OUTPUT --------------- */
namespace __input {
    template<class T> void re(T &x){ cin >> x; }
    void re(lld &x){ string t; cin >> t; x=stold(t); }
    template<class Arg,class...Args> void re(Arg &f,Args &...r){ re(f); re(r...); }
    template<class T1,class T2> void re(pair<T1,T2> &p){ re(p.first,p.second); }
    template<class T> void re(vector<T> &a){ for(auto &x:a) re(x); }
    template<class T, size_t SZ> void re(array<T,SZ> &a){ for(auto &x:a) re(x); }
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

/* --------------- 16) RANDOM HELPER --------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random_in_range(ll l,ll r){
    uniform_int_distribution<ll> dist(l,r);
    return dist(rng);
}

// --------- Number of Shortest Paths ---------

/* --------------- 17) SOLVE --------------- */
void solve(){
    ll n, m; re(n, m);

    vvll adj(n+1);
    vll dist(n+1, 1e9);
    vll num(n+1, 0);
    queue<ll> q;

    rep(i, 0, m) {
        ll u, v; re(u, v);
        adj[u].eb(v), adj[v].eb(u);
    }

    dist[1] = 0;
    num[1] = 1;
    q.push(1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v: adj[u]) {
            if (dist[v] > dist[u] + 1) {
                q.push(v);
                num[v] = num[u];
                dist[v] = dist[u] + 1;
            } else if (dist[v] == dist[u]+1) {
                num[v] = (num[v] + num[u]) % MOD;
            }
        }
    }

    ps(num[n]);
}

/* --------------- 18) MAIN --------------- */
int main(){
    fast_io;
    // set_input_output();
    // If multiple testcases:
    // ll t; cin >> t; while(t--) solve();

    // // Precomputations Needed for Your Code
    // precompute_factorials();   // ✅ Required for nCr(n, r)
    // sieve(MAXN);               // ✅ Required for prime-related functions
    // compute_totient();         // ✅ Required for φ(n) calculations
    // compute_mobius();          // ✅ Required for Möbius function calculations

    cout << setprecision(12) << fixed;

    ll T=1;
    // cin >> T;
    while(T--) solve();

    // #ifdef LOCAL
    //     compare_output();
    // #endif
    return 0;
}
